#ifndef READ_ARGS_H
# define READ_ARGS_H

# include "rtv_structs.h"

t_arguments		*read_arguments(int argc, char **argv);
void			free_arguments(t_arguments *args);

#endif
