/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:21:58 by ldeirdre          #+#    #+#             */
/*   Updated: 2020/12/04 15:13:40 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_structs.h"
#include "scene.h"

static void		put_usage(int argc)
{
	argc = 0;
	ft_putstr("you should choose file from pics/ folder\n");
	ft_putstr("for camera: p.x p.y p.z r.x r.y r.z\n");
	ft_putstr("for light: p.x p.y p.z intensity\n");
	ft_putstr("for shapes: p.x p.y p.z r.x r.y r.z r g b specular\n");
	ft_putstr("for ambient: number\n\n");
	ft_putstr("Have fun! =^.^=\n");
}

int				main(int argc, char **argv)
{
	t_scene		*scene;
	t_rtv		*rtv;
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
