/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/19 15:59:19 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- map_printer() ---------------------------------- */
/*
**		print la map!
**		le paramètre y est là pour vérifier qu'on a bien pu imprimer la map en entier.
**		elle est là pour débuguer mais je pense qu'on pourra la virer ensuite!
*/

void	map_printer(char **map, int y)
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
