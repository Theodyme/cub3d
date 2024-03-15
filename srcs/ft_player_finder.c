/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_finder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/15 19:46:02 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	vector_set(t_vector *vector, double x, double y)
{
	vector->x = x;
	vector->y = y;
	return ;
}

int	orientation_finder(t_mlx *data, char c)

{
	if (c == 'N')
	{
		vector_set(data->dir, 0, -1);
		vector_set(data->plane, 0.66, 0);
	}
	if (c == 'S')
	{
		vector_set(data->dir, 0, 1);
		vector_set(data->plane, -0.66, 0);
	}
	if (c == 'W')
	{
		vector_set(data->dir, -1, 0);
		vector_set(data->plane, 0, -0.66);
	}
	if (c == 'E')
	{
		vector_set(data->dir, 1, 0);
		vector_set(data->plane, 0, 0.66);
	}
	return (0);
}

/* -------------------------- strchr_charset() --------------------- */
/*
**		c'est un strchr mais qui cherche tout caractère
		appartenant au charset précisé.
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

/* ----------------------- player_finder() --------------- */
/*
**		récupère les coordonnées du joueur à l'instant T et les
			stockes dans les data,
**		dans le tableau d'int data->player[1] et data->player[2].
**		par convention, l'axe des abscisses (x, à l'horizontal)
			est toujours cité en premier,
**		suivi de l'axe des ordonnées (y, à la verticale).
		pour plus de clarté, j'ai respecté cette convention!
*/

char	player_finder(t_mlx *data)
{
	int	i;

	i = -1;
	while (data->lvl->map[++i])
	{
		data->square->x = strchr_charset(data->lvl->map[i], "NSEW");
		if (data->square->x != -1)
		{
			data->square->y = i;
			return (data->lvl->map[i][data->square->x]);
		}
	}
	return ('0');
}
