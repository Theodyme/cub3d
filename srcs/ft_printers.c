/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/15 18:03:15 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* --------------------- map_printer() ------------------- */
/*
**		print la map!
**		le paramètre y est là pour vérifier qu'on a bien pu
		imprimer la map en entier.
**		elle est là pour débuguer mais je pense qu'on
		pourra la virer ensuite!
*/

void	map_printer(char **map, int y)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf(BL "map[%d] = [%s]\n" RESET, i, map[i]);
		i++;
	}
	printf("i = %d, y = %d\n", i, y);
	if (i != y)
		printf(RE "ERROR: Couldn't print the full map.\n" RESET);
	return ;
}
