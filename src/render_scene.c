
# include "rtv_structs.h"
# include "vector.h"
# include "scene.h"

void	set_color(t_rtv *rtv, int i, int x, int y)
{
	double	p;
	int		k;
	t_list_node	*cur;
	t_light *svet;
	t_object *tmp;

	tmp = ft_list_at(rtv->scene->objects.begin, i);
	cur = rtv->scene->lights.begin;
	k = 0;
	p = 0;
	while (cur)
	{
		svet = cur->content;
		if (svet->new_inten > 1)
			svet->new_inten = 1;
		p += svet->new_inten;
		if (p > 1)
			p = 1;
		k++;
		cur = cur->next;
	}
	if (i > -1)
	{
		SDL_SetRenderDrawColor(rtv->rend, tmp->color.red * p, 
			tmp->color.green * p, tmp->color.blue * p, 255);
		SDL_RenderDrawPoint(rtv->rend, x, y);
	}
	else
	{
		SDL_SetRenderDrawColor(rtv->rend, 0, 0, 0, 255);
		SDL_RenderDrawPoint(rtv->rend, x, y);
	}
}

void	intersection_check(t_ray *ray, t_rtv *rtv, int x, int y)
{
	int	i;
	t_list_node	*cur;
	t_object *obj;

	i = 0;
	rtv->clos_obj = -1;
	rtv->min_t = INFINITY;
	cur = rtv->scene->objects.begin;
	while (cur)
	{
		obj = cur->content;
		if (obj->type == SPHERE)
			sphere(rtv, ray, i, obj);
		else if (obj->type == PLANE)
			plane(rtv, ray, i, obj);
		else if (obj->type == CYLINDER)
			cylinder(rtv, ray, i, obj);
		else if (obj->type == CONE)
			cone(rtv, ray, i, obj);
		cur = cur->next;
		i++;
	}
	if (rtv->clos_obj > -1)
		light(rtv, ray);
	set_color(rtv, rtv->clos_obj, x, y);
}

void	get_dir(double x, double y, t_ray *ray, t_rtv *rtv)
{
	ray->dir.x = x * (VECTOR_W / (double)rtv->width);
	ray->dir.y = y * (VECTOR_H / (double)rtv->height);
	ray->dir.z = 1.0;
	ray->dir = ft_vecrot(ray->dir, rtv->scene->cam.rot);
}

void 		render_scene(t_rtv *rtv, t_ray *ray)
{
	int		x;
	int		y;
	double	n_x;
	double	n_y;

	x = 0;
	while (x <= rtv->width)
	{
		y = 0;
		n_x = (x + 0.5) / (double)rtv->width;
		n_x = 2 * n_x - 1;
		while (y <= rtv->height)
		{
			n_y = (y + 0.5) / (double)rtv->height;
			n_y = 1 - (2 * n_y);
			get_dir(n_x, n_y, ray, rtv);
			intersection_check(ray, rtv, x, y);
			y++;
		}
		x++;
	}
}
