/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/27 16:46:05 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- data_freer() -------------------------------- */
/*
**		free les structures de données.
*/

void	data_freer(t_mlx *data)
{
	if (data->pos)
		free(data->pos);
	if (data->square)
		free(data->square);
	if (data->dir)
		free(data->dir);
	if (data->plane)
		free(data->plane);
	if (data->rayDir)
		free(data->rayDir);
	if (data->delta)
		free(data->delta);
	if (data->side)
		free(data->side);
}

/* ------------------------------- lvl_freer() -------------------------------- */
/*
**		free la structure lvl.
*/

void	lvl_freer(t_map *lvl)
{
	int	i;

	i = -1;
	if (lvl->lenY > 0)
	{
		while (++i < lvl->lenY)
			free(lvl->map[i]);
		free(lvl->map);
	}
	free(lvl);
}

/* ------------------------------- clear_all() -------------------------------- */
/*
**		free toutes les structures.
*/

void	clear_all(t_mlx *data)
{
    data_freer(data);
    lvl_freer(data->lvl);
    // FAUDRA FREE LES ASSETS POTENTIELLEMENT !
    free(data->assets);
    destroy_win(data);
    exit(0);
    // free(data);
}