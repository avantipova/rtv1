
#include "rtv_structs.h"
#include "read_args.h"
#include "read_scene.h"
#include "app_funcs.h"

int	main(int argc, char **argv)
{
	t_arguments		*args;
	t_scene			*scene;
	t_rtv			*rtv;

	if ((args = read_arguments(argc, argv)))
	{
		if ((scene = read_scene(args)))
		{
			if ((rtv = init_rtv(args, scene)))
			{
				run_app(rtv);
				deinit_rtv(rtv);
			}
			free_scene(scene);
		}
		free_arguments(args);
	}
	return (0);
}
