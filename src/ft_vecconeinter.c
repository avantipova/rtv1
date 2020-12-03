/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecconeinter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:20:44 by ldeirdre          #+#    #+#             */
/*   Updated: 2020/12/03 20:55:40 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "rtv_structs.h"
#include "scene.h"

void			parse_cone(t_scene *scene, char **str)
{
	int			i;
	t_object	tmp;

	i = -1;
	tmp.type = CONE;
	tmp.pos.x = (double)(ft_atoi(str[1]));
	tmp.pos.y = (double)(ft_atoi(str[2]));
	tmp.pos.z = (double)(ft_atoi(str[3]));
	tmp.r = (double)(ft_atoi(str[4])) / 10;
	tmp.rot.x = (double)(ft_atoi(str[5])) / 10;
	tmp.rot.y = (double)(ft_atoi(str[6])) / 10;
	tmp.rot.z = (double)(ft_atoi(str[7])) / 10;
	if (tmp.r < 0.1 || ft_atoi(str[8]) < 0 || ft_atoi(str[9]) < 0
		|| ft_atoi(str[10]) < 0)
		put_error("Wrong input for cone");
	tmp.color.red = (unsigned char)(ft_atoi(str[8]));
	tmp.color.green = (unsigned char)(ft_atoi(str[9]));
	tmp.color.blue = (unsigned char)(ft_atoi(str[10]));
	tmp.specular = (double)(ft_atoi(str[11]));
	while (++i <= 11)
		free(str[i]);
	free(str);
	ft_lstadd(&(scene->objects), ft_lstnew_node(&tmp, sizeof(t_object)));
}

double			cone_intersect(t_vector o, t_vector dir, t_object *obj)
{
	double		a;
	double		b;
	double		c;
	double		d;
	t_vector	x;

	x = ft_vecsub(o, obj->pos);
	a = ft_vecdot(dir, obj->rot);
	a = ft_vecdot(dir, dir) - (1 + obj->r * obj->r) * a * a;
	b = 2 * (ft_vecdot(dir, x) - (1 + obj->r * obj->r) *
		ft_vecdot(dir, obj->rot) * ft_vecdot(x, obj->rot));
	c = ft_vecdot(x, x) - (1 + obj->r * obj->r) *
		pow(ft_vecdot(x, obj->rot), 2);
	d = b * b - 4 * a * c;
	if (d < EPS)
		return (-1);
	return (get_root(a, b, d));
}

t_vector		cone_normal(t_ray *ray, t_object *obj)
{
	double		m;
	t_vector	n;
	t_vector	p;

	m = obj->t * ft_vecdot(ray->dir, obj->rot) +
	ft_vecdot(ft_vecsub(ray->orig, obj->pos), obj->rot);
	p = ft_vecsum(ray->orig, ft_vecscale(ray->dir, obj->t));
	n = ft_vecscale(ft_vecscale(obj->rot, m), (1 + obj->r * obj->r));
	n = ft_vecnorm(ft_vecsub(ft_vecsub(p, obj->pos), n));
	if (ft_vecdot(ray->dir, n) > EPS)
		n = ft_vecscale(n, -1);
	return (n);
}

void			cone(t_rtv *rtv, t_ray *ray, int i, t_object *obj)
{
	obj->t = cone_intersect(ray->orig, ray->dir, obj);
	obj->rot = ft_vecnorm(obj->rot);
	if (obj->t > 0 && obj->t < rtv->min_t)
	{
		rtv->min_t = obj->t;
		rtv->clos_obj = i;
	}
}
