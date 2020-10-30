
#ifndef APP_FUNCS_H
# define APP_FUNCS_H

#include "rtv_structs.h"

t_rtv	*init_rtv(t_arguments *argc, t_scene *scene);
void	run_app(t_rtv *rtv, t_ray *ray);
void	deinit_rtv(t_rtv *rtv);
void 	render_scene(t_rtv *rtv, t_ray *ray);
void	get_dir(double x, double y, t_ray *ray, t_rtv *rtv);
void	intersection_check(t_ray *ray, t_rtv *rtv, int x, int y);
void	light(t_rtv *rtv, t_ray *ray);
void	set_color(t_rtv *rtv, int i, int x, int y);
t_object	*ft_list_at(t_list_node *begin_list, unsigned int nbr);

#endif
