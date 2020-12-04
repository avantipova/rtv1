/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:15:12 by ldeirdre          #+#    #+#             */
/*   Updated: 2020/12/04 15:53:50 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void		put_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

void		parse_camera(t_scene *scene, char **str)
{
	int		i;

	i = -1;
	scene->cam.pos.x = (double)(atoi(str[1]));
	scene->cam.pos.y = (double)(atoi(str[2]));
	scene->cam.pos.z = (double)(atoi(str[3]));
	scene->cam.rot.x = (double)(atoi(str[4]));
	scene->cam.rot.y = (double)(atoi(str[5]));
	scene->cam.rot.z = (double)(atoi(str[6]));
	scene->cams += 1;
	while (++i <= 6)
		free(str[i]);
	free(str);
}

t_scene		*parse_args(char **str, t_scene *scene)
{
	int		i;

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
			put_error("Wrong intensity");
		while (++i <= 1)
			free(str[i]);
		free(str);
	}
	return (scene);
}

t_scene		*read_scene(char *argv)
{
	t_scene	*res;
	char	*line;
	int		fd;
	int		i;
	char	**split;

	i = 0;
	line = NULL;
	fd = 0;
	if (!(res = ft_memalloc(sizeof(t_scene))))
		return (NULL);
	valid_file(fd, argv, i);
	if ((fd = open(argv, O_RDONLY)) < 0)
		put_error("Problem with file opening");
	while ((i = ft_get_next_line(fd, &line)) > 0)
	{
		split = ft_strsplit(line, " ");
		res = parse_args(split, res);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (check_cam(res, argv))
		put_error("No camera");
	close(fd);
	return (res);
}

void		free_scene(t_scene *scene)
{
	free(scene);
}
