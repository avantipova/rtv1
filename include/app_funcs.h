
#ifndef APP_FUNCS_H
# define APP_FUNCS_H

#include "rtv_structs.h"

t_rtv	*init_rtv(t_arguments *argc, t_scene *scene);
void	run_app(t_rtv *rtv);
void	deinit_rtv(t_rtv *rtv);
void 	render_scene(SDL_Renderer *rend, t_scene *scene);

#endif
