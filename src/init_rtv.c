#include "scene.h"

t_rtv		*init_rtv(t_scene *scene)
{
	t_rtv	*res;

	if (!(res = ft_memalloc(sizeof(t_rtv))))
		return (NULL);
	res->scene = scene;
	res->width = 800;
	res->height = 800;

	SDL_Init(0);
	res->window = SDL_CreateWindow(scene->fname,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			res->width,
			res->height,
			0);
	res->rend = SDL_CreateRenderer(res->window, -1, 0);
	return (res);
}

static void	free_rtv(t_rtv *rtv)
{
	free(rtv);
}

void		deinit_rtv(t_rtv *rtv)
{
	SDL_DestroyRenderer(rtv->rend);
	SDL_DestroyWindow(rtv->window);
	SDL_Quit();
	free_rtv(rtv);
}
