/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:21:53 by ldeirdre          #+#    #+#             */
/*   Updated: 2020/12/04 15:34:48 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_structs.h"
#include "vector.h"
#include "scene.h"

void			parse_light(t_scene *scene, char **str)
{
	int			i;
	t_light		light;

	i = -1;
	light.pos.x = (double)(ft_atoi(str[1]));
	light.pos.y = (double)(ft_atoi(str[2]));
	light.pos.z = (double)(ft_atoi(str[3]));
	light.inten = (double)(ft_atoi(str[4])) / 100;
	if (light.inten < 0)
		put_error("Wrong intensity parameter");
	light.new_inten = 1;
	while (++i <= 4)
		free(str[i]);
	free(str);
	ft_lstadd(&(scene->lights), ft_lstnew_node(&light, sizeof(t_light)));
}

double			check_object(t_object *obj, t_light *light, t_vector dir)
{
	double		t;

	t = 0;
	if (obj->type == SPHERE)
		t = sphere_intersect(light->p, dir, obj);
	else if (obj->type == PLANE)
		t = plane_intersect(light->p, dir, obj);
	else if (obj->type == CONE)
		t = cone_intersect(light->p, dir, obj);
	else if (obj->type == CYLINDER)
		t = cylinder_intersect(light->p, dir, obj);
	return (t);
}

int				shadow_init(t_light *light, t_rtv *rtv)
{
	double		max;
	double		t;
	t_vector	dir;
	t_list_node	*cur;
	t_object	*obj;

	t = 0;
	cur = rtv->scene->objects.begin;
	max = ft_veclen(ft_vecsub(light->pos, light->p));
	dir = ft_vecnorm(ft_vecsub(light->pos, light->p));
	light->p = ft_vecsum(light->p, ft_vecscale(dir, EPS));
	while (cur)
	{
		obj = cur->content;
		t = check_object(obj, light, dir);
		if (t > 0.00001 && t < max)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void			get_intensity(t_rtv *rtv, t_light *light, t_vector v, double s)
{
	double		n_dot_l;
	double		r_dot_v;
	double		inten;
	t_vector	l;
	t_vector	r;

	light->new_inten = rtv->scene->ambient;
	inten = 0.0;
	l = ft_vecnorm(ft_vecsub(light->pos, light->p));
	n_dot_l = ft_vecdot(light->n, l);
	if (shadow_init(light, rtv) == 0)
		inten = light->inten;
	if ((n_dot_l) > EPS)
		light->new_inten += inten * ((n_dot_l) / (ft_veclen(light->n) *
					ft_veclen(l)));
	if (s > 0)
	{
		r = ft_vecscale(light->n, 2);
		r = ft_vecscale(r, ft_vecdot(light->n, l));
		r = ft_vecsub(r, l);
		r_dot_v = ft_vecdot(r, v);
		if ((r_dot_v) > EPS)
			light->new_inten += inten * pow(((r_dot_v) / (ft_veclen(r) *
							ft_veclen(v))), s);
	}
}

void			light(t_rtv *rtv, t_ray *ray)
{
	t_list_node	*cur;
	t_light		*svet;
	t_object	*closest;

	cur = rtv->scene->lights.begin;
	closest = ft_list_at(rtv->scene->objects.begin, rtv->clos_obj);
	if (rtv->clos_obj > -1)
	{
		while (cur)
		{
			svet = cur->content;
			svet->p = ft_vecsum(ray->orig, ft_vecscale(ray->dir, closest->t));
			if (closest->type == SPHERE)
				svet->n = sphere_normal(ray, closest);
			else if (closest->type == PLANE)
				svet->n = closest->rot;
			else if (closest->type == CYLINDER)
				svet->n = cyl_normal(ray, closest);
			else if (closest->type == CONE)
				svet->n = cone_normal(ray, closest);
			get_intensity(rtv, svet, ft_vecscale(ray->dir, -1),
					closest->specular);
			cur = cur->next;
		}
	}
}
