/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/19 14:29:24 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_map_printer(char **map, int y)
{
	int	i;

	i = 0;
	while (map[i] && i <= y)
	{
		printf(BL "map[%d] = [%s]\n" RESET, i, map[i]);
		i++;
	}
	if (i != y + 1)
		printf(RE "ERROR: Couldn't print the full map.\n" RESET);
	return ;
}
