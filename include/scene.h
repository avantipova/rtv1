
#ifndef READ_SCENE_H
# define READ_SCENE_H

# include "rtv_structs.h"
#include <fcntl.h>	
#include <sys/stat.h>	
#include <sys/types.h>

t_scene	*read_scene(char *argv);
void	free_scene(t_scene *scene);
t_vector	cone_normal(t_ray *ray, t_object *obj);
void	cone(t_rtv *sdl, t_ray *ray, int i, t_object *obj);
double	cylinder_intersect(t_vector o, t_vector dir, t_object *obj);
t_vector	cyl_normal(t_ray *ray, t_object *obj);
void	cylinder(t_rtv *sdl, t_ray *ray, int i, t_object *obj);
t_vector	plane_normal(t_ray *ray, t_object *obj);
double	plane_intersect(t_vector o, t_vector dir, t_object *obj);
void	plane(t_rtv *sdl, t_ray *ray, int i, t_object *obj);
void	sphere(t_rtv *rtv, t_ray *ray, int i, t_object *obj);
double	sphere_intersect(t_vector o, t_vector dir, t_object *obj);
double	get_root(double a, double b, double d);
t_vector	sphere_normal(t_ray *ray, t_object *obj);
int		shadow_init(t_light *light, t_rtv *rtv);
void	get_intensity(t_rtv *rtv, t_light *light, t_vector v, double s);
double	cone_intersect(t_vector o, t_vector dir, t_object *obj);
void	light(t_rtv *rtv, t_ray *ray);
t_object	*ft_list_at(t_list_node *begin_list, unsigned int nbr);
t_light	*ft_list_atlight(t_list_node *begin_list, unsigned int nbr);
void	put_error(char *str);
void parse_camera(t_scene *scene, char **str);
t_scene	 *parse_args(char **str, t_scene *scene);
void	parse_cone(t_scene *scene, char **str);
void	parse_cylinder(t_scene *scene, char **str);
void	parse_plane(t_scene *scene, char **str);
void	parse_sphere(t_scene *scene, char **str);
void	parse_light(t_scene *scene, char **str);
int		line_valid(char *line);
int		val_nb(char *str);
void	val_1(char **str, int k);
void	valid(char **str);
void	valid_file(int fd, char *argv, int i);
t_rtv	*init_rtv(t_scene *scene);
void	run_app(t_rtv *rtv, t_ray *ray);
void	deinit_rtv(t_rtv *rtv);
void 	render_scene(t_rtv *rtv, t_ray *ray);
void	get_dir(double x, double y, t_ray *ray, t_rtv *rtv);
void	intersection_check(t_ray *ray, t_rtv *rtv, int x, int y);
void	light(t_rtv *rtv, t_ray *ray);
void	set_color(t_rtv *rtv, int i, int x, int y);
t_object	*ft_list_at(t_list_node *begin_list, unsigned int nbr);
#endif
