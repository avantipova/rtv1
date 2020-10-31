#include "vector.h"
#include <math.h>
#include "rtv_structs.h"
#include "read_scene.h"

void	parse_sphere(t_scene *scene, char **str)
{
	int i;
	t_object tmp;

	i = -1;
	tmp.type = SPHERE;
	tmp.pos.x = (double)(ft_atoi(str[1]));
	tmp.pos.y = (double)(ft_atoi(str[2]));
	tmp.pos.z = (double)(ft_atoi(str[3]));
	tmp.r = (double)(ft_atoi(str[4])) / 10;
	if (tmp.r < 0.1 || ft_atoi(str[5]) < 0 || ft_atoi(str[6]) < 0
		|| ft_atoi(str[7]) < 0)
		put_error("Wrong input for sphere");
	tmp.color.red = (unsigned char)(ft_atoi(str[5]));
	tmp.color.green = (unsigned char)(ft_atoi(str[6]));
	tmp.color.blue= (unsigned char)(ft_atoi(str[7]));
	tmp.specular = (double)(ft_atoi(str[8]));
	while (++i <= 8)
		free(str[i]);
	free(str);
	ft_lstadd(&(scene->objects), ft_lstnew_node(&tmp, sizeof(t_object)));
}

t_vector	sphere_normal(t_ray *ray, t_object *obj)
{
	t_vector n;

	n = ft_vecsum(ray->orig, ft_vecscale(ray->dir, obj->t));
	n = ft_vecnorm(ft_vecsub(n, obj->pos));
	if (ft_vecdot(ray->dir, n) > EPS)
		n = ft_vecscale(n, -1);
	return (n);
}

double	get_root(double a, double b, double d)
{
	double t1;
	double t2;

	t1 = (-b - sqrt(d)) / (2 * a);
	t2 = (-b + sqrt(d)) / (2 * a);
	if ((t1 <= t2 && t1 >= 0) || (t1 >= 0 && t2 < 0))
		return (t1);
	else if ((t2 <= t1 && t2 >= 0) || (t1 < 0 && t2 >= 0))
		return (t2);
	return (-1);
}

double	sphere_intersect(t_vector o, t_vector dir, t_object *obj)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vector	oc;

	oc = ft_vecsub(o, obj->pos);
	a = ft_vecdot(dir, dir);
	b = 2 * ft_vecdot(oc, dir);
	c = ft_vecdot(oc, oc) - (obj->r * obj->r);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	return (get_root(a, b, d));
}

void	sphere(t_rtv *rtv, t_ray *ray, int i, t_object *obj)
{
	obj->t = sphere_intersect(ray->orig, ray->dir, obj);
	if (obj->t > 0 && obj->t < rtv->min_t)
	{
		rtv->min_t = obj->t;
		rtv->clos_obj = i;
	}
}