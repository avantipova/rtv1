#include "vector.h"
#include <math.h>
#include <float.h>
#include "stdio.h"
#include "rtv_structs.h"
#include "read_scene.h"

t_vector	plane_normal(t_ray *ray, t_object *obj)
{
	if (ft_vecdot(ray->dir, obj->rot) < 0)
		return (obj->rot);
	return (ft_vecscale(obj->rot, -1));
}

double	plane_intersect(t_vector o, t_vector dir, t_object *obj)
{
	double	t;
	double	a;
	double	b;
	t_vector	x;

	x = ft_vecsub(o, obj->pos);
	a = ft_vecdot(x, obj->rot);
	b = ft_vecdot(dir, obj->rot);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (-1);
	t = -a / b;
	if (t > EPS)
		return (t);
	return (-1);
}

void	plane(t_rtv *sdl, t_ray *ray, int i, t_object *obj)
{
	obj->rot = ft_vecnorm(obj->rot);
	obj->t = plane_intersect(ray->orig, ray->dir, obj);
	if (obj->t > 0 && obj->t < sdl->min_t)
	{
		sdl->min_t = obj->t;
		sdl->clos_obj = i;
	}
}
