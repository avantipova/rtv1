/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:31:21 by ldeirdre          #+#    #+#             */
/*   Updated: 2020/12/03 20:49:01 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (e.key.keysym.sym == SDLK_UP)
				turn_left(rtv, ray);
			if (e.key.keysym.sym == SDLK_DOWN)
				turn_right(rtv, ray);
			if (e.key.keysym.sym == SDLK_RIGHT)
				go_up(rtv, ray);
			if (e.key.keysym.sym == SDLK_LEFT)
				go_down(rtv, ray);
		}
	}
}
