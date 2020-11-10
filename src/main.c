
#include "rtv_structs.h"
#include "scene.h"

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
			if (e.type == SDL_QUIT)
				status = 0;
		}
	}
}

int	main(int argc, char **argv)
{
	t_scene			*scene;
	t_rtv			*rtv;
	t_ray		*ray;

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