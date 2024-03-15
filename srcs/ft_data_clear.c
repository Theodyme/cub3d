/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/15 17:10:51 by flplace          ###   ########.fr       */
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
	mlx_destroy_image(data->mlx, data->raycasting.mlx_img);
	if (data->assets != NULL)
	{
		mlx_destroy_image(data->mlx, data->assets->nwall->mlx_img);
		free(data->assets->nwall);
		mlx_destroy_image(data->mlx, data->assets->wwall->mlx_img);
		free(data->assets->wwall);
		mlx_destroy_image(data->mlx, data->assets->swall->mlx_img);
		free(data->assets->swall);
		mlx_destroy_image(data->mlx, data->assets->ewall->mlx_img);
		free(data->assets->ewall);
	}
	// mlx_destroy_image(data->mlx, &data->minimap);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
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
	if (data->moves)
		free(data->moves);
	if (data->square)
		free(data->square);
	if (data->step)
		free(data->step);
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
	if (data->draw)
		free(data->draw);
}

/* ------------------------------- lvl_freer() -------------------------------- */
/*
**		free la structure lvl.
*/

void	lvl_freer(t_map *lvl)
{
	int	i;

	i = 0;
	if (lvl->lenY > 0)
	{
		while (i < lvl->lenY)
		{
			free(lvl->map[i]);
			i++;
		}
		if (lvl->map[i] != NULL)
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
    destroy_win(data);
	free(data->mlx);
    free(data->assets);
    exit(0);
    // free(data);
}
