#include "vector.h"
#include <math.h>
#include "rtv_structs.h"
# include "read_scene.h"

double	cone_intersect(t_vector o, t_vector dir, t_object *obj)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vector	x;

	x = ft_vecsub(o, obj->pos);
	a = ft_vecdot(dir, obj->rot);
	a = ft_vecdot(dir, dir) - (1 + obj->r * obj->r) * a * a;
	b = 2 * (ft_vecdot(dir, x) - (1 + obj->r * obj->r) *
		ft_vecdot(dir, obj->rot) * ft_vecdot(x, obj->rot));
	c = ft_vecdot(x, x) - (1 + obj->r * obj->r) * pow(ft_vecdot(x, obj->rot), 2);
	d = b * b - 4 * a * c;
	if (d < EPS)
		return (-1);
	return (get_root(a, b, d));
}

t_vector	cone_normal(t_ray *ray, t_object *obj)
{
	double	m;
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

void	cone(t_rtv *rtv, t_ray *ray, int i, t_object *obj)
{
	obj->t = cone_intersect(ray->orig, ray->dir, obj);
	obj->rot = ft_vecnorm(obj->rot);
	if (obj->t > 0 && obj->t < rtv->min_t)
	{
		rtv->min_t = obj->t;
		rtv->clos_obj = i;
	}
}