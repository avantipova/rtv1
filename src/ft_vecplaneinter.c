#include "vector.h"
#include "stdio.h"
#include "rtv_structs.h"
#include "scene.h"

void	parse_plane(t_scene *scene, char **str)
{
	int i;
	t_object tmp;

	i = -1;
	tmp.type = PLANE;
	tmp.pos.x = (double)(ft_atoi(str[1]));
	tmp.pos.y = (double)(ft_atoi(str[2]));
	tmp.pos.z = (double)(ft_atoi(str[3]));
	tmp.rot.x = (double)(ft_atoi(str[4]));
	tmp.rot.y = (double)(ft_atoi(str[5]));
	tmp.rot.z = (double)(ft_atoi(str[6]));
	if (ft_atoi(str[7]) < 0 || ft_atoi(str[8]) < 0 || ft_atoi(str[9]) < 0)
		put_error("Wrong input");
	tmp.color.red = (unsigned char)(ft_atoi(str[7]));
	tmp.color.green = (unsigned char)(ft_atoi(str[8]));
	tmp.color.blue = (unsigned char)(ft_atoi(str[9]));
	tmp.specular = (double)(ft_atoi(str[10]));
	while (++i <= 10)
		free(str[i]);
	free(str);
	ft_lstadd(&(scene->objects), ft_lstnew_node(&tmp, sizeof(t_object)));
}




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
