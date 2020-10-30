
#include "rtv_structs.h"
#include "read_args.h"
#include "read_scene.h"
#include "app_funcs.h"

int	main(int argc, char **argv)
{
	t_arguments		*args;
	t_scene			*scene;
	t_rtv			*rtv;
	t_ray		*ray;

	if (!(ray = ft_memalloc(sizeof(t_ray))))
		return (NULL);
	if ((args = read_arguments(argc, argv)))
	{
		if ((scene = read_scene(args)))
		{
			if ((rtv = init_rtv(args, scene)))
			{
				ray->orig.x = rtv->scene->cam.pos.x;
				ray->orig.y = rtv->scene->cam.pos.y;
				ray->orig.z = rtv->scene->cam.pos.z;
				run_app(rtv, ray);
				deinit_rtv(rtv);
			}
			free_scene(scene);
		}
		free_arguments(args);
	}
	return (0);
}
