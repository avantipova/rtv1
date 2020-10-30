
#include "read_scene.h"

#include "../libft/include/ft_list.h"


t_scene	*read_scene(t_arguments	*args)
{
	t_scene	*res;

	if (!(res = ft_memalloc(sizeof(t_scene))))
		return (NULL);

	res->cam.pos.x = 0;
	res->cam.pos.y = 1;
	res->cam.pos.z = -100;
	res->cam.rot.x = 0;
	res->cam.rot.y = 0;
	res->cam.rot.z = 0;

	t_object	tmp;
	t_light		light;

	tmp.type = PLANE;
	tmp.pos.x = 0;
	tmp.pos.y = -2;
	tmp.pos.z = 25;
	tmp.rot.x = 0;
	tmp.rot.y = 1;
	tmp.rot.z = 0;
	tmp.color.red = 59;
	tmp.color.green = 60;
	tmp.color.blue = 195;
	tmp.specular = 200;
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));


	tmp.type = CYLINDER;
	tmp.pos.x = -2;
	tmp.pos.y = 0;
	tmp.pos.z = 30;
	tmp.r = (double)4 / 10;
	tmp.rot.x = 0;
	tmp.rot.y = 1;
	tmp.rot.z = 0;
	tmp.color.red = 255;
	tmp.color.green = 0;
	tmp.color.blue = 0;
	tmp.specular = 200;
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));

	tmp.type = CONE;
	tmp.pos.x = 3;
	tmp.pos.y = 0;
	tmp.pos.z = 60;
	tmp.r = (double)3 / 10;
	tmp.rot.x = 1;
	tmp.rot.y = 1;
	tmp.rot.z = 1;
	tmp.color.red = 255;
	tmp.color.green = 255;
	tmp.color.blue = 0;
	tmp.specular = 0.002;
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));

tmp.type = CYLINDER;
	tmp.pos.x = 2;
	tmp.pos.y = 0;
	tmp.pos.z = 30;
	tmp.r = (double)4 / 10;
	tmp.rot.x = 0;
	tmp.rot.y = 1;
	tmp.rot.z = 0;
	tmp.color.red = 0;
	tmp.color.green = 0;
	tmp.color.blue = 255;
	tmp.specular = 50;
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));


	tmp.type = SPHERE;
	tmp.pos.x = -2;
	tmp.pos.y = -2;
	tmp.pos.z = 30;
	tmp.r = (double)60 / 10;
	tmp.color.red = 200;
	tmp.color.green = 111;
	tmp.color.blue = 137;
	tmp.specular = 10;
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));

	tmp.type = SPHERE;
	tmp.pos.x = 1;
	tmp.pos.y = -2;
	tmp.pos.z = 5;
	tmp.r = (double)30 / 10;
	tmp.color.red = 102;
	tmp.color.green = 255;
	tmp.color.blue = 137;
	tmp.specular = 100;
	ft_lstadd(&(res->objects), ft_lstnew_node(&tmp, sizeof(t_object)));


	light.pos.x = 3;
	light.pos.y = 3;
	light.pos.z = 20;
	light.inten = 70.0 / 100.0;
	light.new_inten = 1;

	ft_lstadd(&(res->lights), ft_lstnew_node(&light, sizeof(t_light)));

	light.pos.x = -3;
	light.pos.y = 1;
	light.pos.z = 25;
	light.inten = 40.0 / 100.0;
	light.new_inten = 1;

	ft_lstadd(&(res->lights), ft_lstnew_node(&light, sizeof(t_light)));


	return (res);
}

void	free_scene(t_scene *scene)
{
	free(scene);
}
