/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:22:05 by ldeirdre          #+#    #+#             */
/*   Updated: 2020/12/04 15:18:22 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int		val_nb(char *str)
{
	int	i;

	if (str[0] == '-' || str[0] == '+')
		i = 1;
	else
		i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			put_error("Input is not number");
	}
	return (1);
}

void	val_1(char **str, int k)
{
	int i;

	i = 0;
	while (++i <= k)
		if (!str[i] || (atoi(str[i]) == 0 && str[i][0] != '0') ||
				str[k + 1] != NULL || !val_nb(str[i]))
			put_error("Wrong input");
	i = -1;
	while (++i <= k)
		free(str[i]);
	free(str);
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

void	valid_file(int fd, char *argv, int i)
{
	char	*line;
	char	**split;

	line = NULL;
	if ((fd = open(argv, O_RDONLY)) < 0)
		put_error("Problem with file opening");
	while ((i = ft_get_next_line(fd, &line)) > 0)
	{
		if (line_valid(line) == 0)
			put_error("Wrong input");
		split = ft_strsplit(line, " ");
		ft_strdel(&line);
		valid(split);
	}
	ft_strdel(&line);
	close(fd);
}
