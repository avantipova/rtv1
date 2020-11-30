
#include "rtv_structs.h"
#include "scene.h"


void	turn_left(t_rtv *rtv, t_ray *ray)
{
	rtv->scene->cam.rot.x -= 0.1;
	render_scene(rtv, ray);
	SDL_RenderPresent(rtv->rend);
}

void	turn_right(t_rtv *rtv, t_ray *ray)
{
	rtv->scene->cam.rot.x += 0.1;
	render_scene(rtv, ray);
	SDL_RenderPresent(rtv->rend);
}

void	go_up(t_rtv *rtv, t_ray *ray)
{
	rtv->scene->cam.rot.y += 0.1;
	render_scene(rtv, ray);
	SDL_RenderPresent(rtv->rend);
}

void	go_down(t_rtv *rtv, t_ray *ray)
{
	rtv->scene->cam.rot.y -= 0.1;
	render_scene(rtv, ray);
	SDL_RenderPresent(rtv->rend);
}

void	run_app(t_rtv *rtv, t_ray *ray)
{
	int				status;
	SDL_Event		e;

	status = 1;
	SDL_SetRenderDrawColor(rtv->rend, 0, 0, 0, 0xFF);
	SDL_RenderClear(rtv->rend);
	render_scene(rtv, ray);
	SDL_RenderPresent(rtv->rend);
	while (status)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				status = 0;
			if (e.key.keysym.sym == SDLK_LEFT)
				turn_left(rtv, ray);
			if (e.key.keysym.sym == SDLK_RIGHT)
				turn_right(rtv, ray);
			if (e.key.keysym.sym == SDLK_UP)
				go_up(rtv, ray);
			if (e.key.keysym.sym == SDLK_DOWN)
				go_down(rtv, ray);
		}
	}
}

static void	put_usage(int argc)
{
	argc = 0;
	ft_putstr("you should choose file from pics/ folder\n");
	ft_putstr("for camera: p.x p.y p.z r.x r.y r.z\n");
	ft_putstr("for light: p.x p.y p.z intensity\n");
	ft_putstr("for shapes: p.x p.y p.z r.x r.y r.z r g b specular\n");
	ft_putstr("for ambient: number\n\n");
	ft_putstr("Have fun! =^.^=\n");
}

int	main(int argc, char **argv)
{
	t_scene			*scene;
	t_rtv			*rtv;
	t_ray		*ray;

	if (argc == 1)
		put_usage(argc);
	if (!(ray = ft_memalloc(sizeof(t_ray))) || argc != 2)
		return (0);
	if ((scene = read_scene(argv[1])))
	{
		if ((rtv = init_rtv(scene)))
		{
			ray->orig.x = rtv->scene->cam.pos.x;
			ray->orig.y = rtv->scene->cam.pos.y;
			ray->orig.z = rtv->scene->cam.pos.z;
			run_app(rtv, ray);
			deinit_rtv(rtv);
		}
		free_scene(scene);
	}
	return (0);
}