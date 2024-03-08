/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/08 17:04:16 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- destroy_window() ---------------------------------- */
/*
**		appelée dans le clear_all().
**		assez straightforward: elle détruit l'image et le display.
**
*/

int	    destroy_win(t_mlx *data)
{
	// mlx_destroy_image(data->mlx, &data->raycasting);
	// mlx_destroy_image(data->mlx, &data->minimap);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	return (0);
}

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
	if (data->ray)
		free(data->ray);
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
