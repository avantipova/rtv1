

#include "../libft/include/ft_list.h"
#include <fcntl.h>	
#include <sys/stat.h>	
#include <sys/types.h>
#include "read_scene.h"


void	put_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void parse_camera(t_scene *scene, char **str)
{
	int i;

	i = -1;
	scene->cam.pos.x = (double)(atoi(str[1]));
	scene->cam.pos.y = (double)(atoi(str[2]));
	scene->cam.pos.z = (double)(atoi(str[3]));
	scene->cam.rot.x = (double)(atoi(str[4]));
	scene->cam.rot.y = (double)(atoi(str[5]));
	scene->cam.rot.z = (double)(atoi(str[6]));
	scene->cams = 1;
	while (++i <= 6)
		free(str[i]);
	free(str);
}

t_scene	 *parse_args(char **str, t_scene *scene)
{
	int i;

	i = -1;
	if (ft_strequ(str[0], "camera:"))
		parse_camera(scene, str);
	else if (ft_strequ(str[0], "light:"))
		parse_light(scene, str);
	else if (ft_strequ(str[0], "sphere:"))
		parse_sphere(scene, str);
	else if (ft_strequ(str[0], "plane:"))
		parse_plane(scene, str);
	else if (ft_strequ(str[0], "cylinder:"))
		parse_cylinder(scene, str);
	else if (ft_strequ(str[0], "cone:"))
		parse_cone(scene, str);
	else if (ft_strequ(str[0], "ambient:"))
	{
		scene->ambient = (double)(atoi(str[1])) / 100;
		if (scene->ambient < 0)
			put_error("Wrong intensity aka ambient");
		while (++i <= 1)
			free(str[i]);
		free(str);
	}
	return (scene);
}

int		line_valid(char *line)
{
	if (ft_strncmp("camera: ", line, 5) == 0)
		return (1);
	if (ft_strncmp("light: ", line, 7) == 0)
		return (1);
	if (ft_strncmp("sphere: ", line, 8) == 0)
		return (1);
	if (ft_strncmp("cone: ", line, 6) == 0)
		return (1);
	if (ft_strncmp("cylinder: ", line, 10) == 0)
		return (1);
	if (ft_strncmp("plane: ", line, 7) == 0)
		return (1);
	if (ft_strncmp("ambient: ", line, 9) == 0)
		return (1);
	return (0);
}

void	valid(char **str)
{
	int i;

	i = 0;
	if (ft_strequ(str[0], "camera:"))
		val_1(str, 6);
	else if (ft_strequ(str[0], "sphere:"))
		val_1(str, 8);
	else if (ft_strequ(str[0], "plane:"))
		val_1(str, 10);
	else if (ft_strequ(str[0], "cylinder:"))
		val_1(str, 11);
	else if (ft_strequ(str[0], "cone:"))
		val_1(str, 11);
	else if (ft_strequ(str[0], "light:"))
		val_1(str, 4);
	else if (ft_strequ(str[0], "ambient:"))
		val_1(str, 1);
}

t_scene	*read_scene(char *argv)
{
	t_scene	*res;
	char	*line;
	int		fd;
	int		i;
	char	**split;

	i = 0;
	fd = 0;
	line = NULL;
	if (!(res = ft_memalloc(sizeof(t_scene))))
		return (NULL);
	if ((fd = open(argv, O_RDONLY)) < 0)
		put_error("Can't open the file");
	res->fname = argv;
	while ((i = ft_get_next_line(fd, &line)) > 0)
	{
		if (line_valid(line) == 0)
			put_error("Wrong input");
		split = ft_strsplit(line, " ");
		res = parse_args(split, res);
		ft_strdel(&line);
		valid(split);
	}
	ft_strdel(&line);
	if (res->cams != 1)
		put_error("Have no camera");
	close(fd);
	return (res);
}

void	free_scene(t_scene *scene)
{
	free(scene);
}
