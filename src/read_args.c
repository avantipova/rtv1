
#include "read_args.h"
//#include "ft_string.h"



t_arguments		*read_arguments(int argc, char **argv)
{
	t_arguments	*res;

	if (!(res = ft_memalloc(sizeof(t_arguments))))
		return (NULL);
	res->w_height = 700;
	res->w_width = 700;
	res->fname = argv[0];
	argc = 0;
	return (res);
}

void			free_arguments(t_arguments *args)
{
	free(args);
}
