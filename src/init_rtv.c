/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rtv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:21:38 by ldeirdre          #+#    #+#             */
/*   Updated: 2020/12/04 15:53:36 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_rtv		*init_rtv(t_scene *scene)
{
	t_rtv	*res;

	if (!(res = ft_memalloc(sizeof(t_rtv))))
		return (NULL);
	res->scene = scene;
	res->width = 800;
	res->height = 800;
	res->scene->cams = 0;
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

int			check_cam(t_scene *res, char *argv)
{
	res->fname = argv;
	if (res->cams != 1)
		return (1);
	else
		return (0);
}
