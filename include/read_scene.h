
#ifndef READ_SCENE_H
# define READ_SCENE_H

# include "rtv_structs.h"

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
#endif
