/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/19 15:07:18 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	strchr_charset(char *str, char *charset)
{
	int	i;

	i = -1;
	if (str == NULL || charset == NULL)
		return (-1);
	while (str[++i])
	{
		if (ft_is_in_charset(str[i], charset) != 0)
			return (i);
	}
	return (-1);
}

void	player_finder(t_mlx **vars)
{
	int	i;

	i = -1;
	// ft_map_printer((*vars)->lvl->map, (*vars)->lvl->y);
	while ((*vars)->lvl->map[++i])
	{
		(*vars)->player[0] = strchr_charset((*vars)->lvl->map[i], "NSEW");
		if ((*vars)->player[0] != -1)
		{
			// printf("Found player at (%d, %d)\n", ((*vars)->player[0]), i);
			(*vars)->player[1] = i;
			return ;
		}
	}
	return ;
}
