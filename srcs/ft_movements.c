/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/19 16:03:06 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- strchr_charset() ---------------------------------- */
/*
**		c'est un strchr mais qui cherche tout caractère appartenant au charset précisé.
**		je l'ai utilisé parce que le player peut être désigné par NSWE.
*/

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

/* ------------------------------- player_finder() ---------------------------------- */
/*
**		récupère les coordonnées du joueur à l'instant T et les stockes dans les data,
**		dans le tableau d'int data->player[1] et data->player[2].
**		par convention, l'axe des abscisses (x, à l'horizontal) est toujours cité en premier,
**		suivi de l'axe des ordonnées (y, à la verticale). pour plus de clarté, j'ai respecté
**		cette convention!
*/

void	player_finder(t_mlx **data)
{
	int	i;

	i = -1;
	// map_printer((*data)->lvl->map, (*data)->lvl->y);
	while ((*data)->lvl->map[++i])
	{
		(*data)->player[0] = strchr_charset((*data)->lvl->map[i], "NSEW");
		if ((*data)->player[0] != -1)
		{
			// printf("Found player at (%d, %d)\n", ((*data)->player[0]), i);
			(*data)->player[1] = i;
			return ;
		}
	}
	return ;
}
