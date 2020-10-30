#ifndef READ_ARGS_H
# define READ_ARGS_H

# include "rtv_structs.h"

t_arguments		*read_arguments(int argc, char **argv);
void			free_arguments(t_arguments *args);
double	cone_intersect(t_vector o, t_vector dir, t_object *obj);

#endif
