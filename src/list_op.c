/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:48:50 by ldeirdre          #+#    #+#             */
/*   Updated: 2020/12/03 20:49:31 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rtv_structs.h"
# include "vector.h"
# include "scene.h"

t_object	*ft_list_at(t_list_node *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list)
	{
		if (i == nbr)
			return (begin_list->content);
		begin_list = begin_list->next;
		i++;
	}
	return (0);
}

t_light	*ft_list_atlight(t_list_node *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list)
	{
		if (i == nbr)
			return (begin_list->content);
		begin_list = begin_list->next;
		i++;
	}
	return (0);
}