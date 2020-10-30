#include "vector.h"
#include <math.h>
#include "rtv_structs.h"
# include "read_scene.h"

double	cylinder_intersect(t_vector o, t_vector dir, t_object *obj)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vector	x;

	x = ft_vecsub(o, obj->pos);
	a = ft_vecdot(dir, dir) - pow(ft_vecdot(dir, obj->rot), 2);
	b = 2 * (ft_vecdot(dir, x) - (ft_vecdot(dir, obj->rot) * ft_vecdot(x, obj->rot)));
	c = ft_vecdot(x, x) - pow(ft_vecdot(x, obj->rot), 2) - pow(obj->r, 2);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	return (get_root(a, b, d));
}

t_vector	cyl_normal(t_ray *ray, t_object *obj)
{
	double	m;
	t_vector	n;
	t_vector	p;

	m = obj->t * ft_vecdot(ray->dir, obj->rot) +
	ft_vecdot(ft_vecsub(ray->orig, obj->pos), obj->rot);
	p = ft_vecsum(ray->orig, ft_vecscale(ray->dir, obj->t));
	n = ft_vecnorm(ft_vecsub(ft_vecsub(p, obj->pos), ft_vecscale(obj->rot, m)));
	if (ft_vecdot(ray->dir, n) > EPS)
		n = ft_vecscale(n, -1);
	return (n);
}

void	cylinder(t_rtv *sdl, t_ray *ray, int i, t_object *obj)
{
	obj->t = cylinder_intersect(ray->orig, ray->dir, obj);
	obj->rot = ft_vecnorm(obj->rot);
	if (obj->t > 0 && obj->t < sdl->min_t)
	{
		sdl->min_t = obj->t;
		sdl->clos_obj = i;
	}
}