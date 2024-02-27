/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/27 15:57:04 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- data_alloc() -------------------------------- */
/*
**		alloue la mémoire pour les structures de données.
*/

void	data_alloc(t_mlx *data)
{
	if (data != NULL)
	{
		data->pos = malloc(sizeof(t_pos));
		data->square = malloc(sizeof(t_square));
		data->dir = malloc(sizeof(t_dir));
		data->plane = malloc(sizeof(t_plane));
		data->rayDir = malloc(sizeof(t_rayDir));
		data->delta = malloc(sizeof(t_deltaDist));
		data->side = malloc(sizeof(t_sideDist));
	}
	if (!(data->pos) || !(data->square) || !(data->dir) || !(data->plane) || !(data->rayDir) || !(data->delta) || !(data->side))
		data_freer(data);
	return ;
}

/* ------------------------------- data_init() -------------------------------- */
/*
**		initialise les structures de données.
*/

void	data_init(t_mlx *data)
{
	data_alloc(data);
	data->pos->x = 0;
	data->pos->y = 0;
	data->square->x = 0;
	data->square->y = 0;
	data->dir->x = 0;
	data->dir->y = 0;
	data->plane->x = 0;
	data->plane->y = 0;
	data->camerax = 0;
	data->time = 0;
	data->oldTime = 0;
	data->rayDir->x = 0;
	data->rayDir->y = 0;
	data->delta->x = 0;
	data->delta->y = 0;
	data->side->x = 0;
	data->side->y = 0;
	return ;
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
	if (data->rayDir)
		free(data->rayDir);
	if (data->delta)
		free(data->delta);
	if (data->side)
		free(data->side);
	// free(data);
	// data = NULL; 
}

/* ------------------------------- assets_init() -------------------------------- */
/*
**		initialise les structures d'assets.
*/

void	assets_init(t_assets *assets)
{
	assets->nwall = NULL;
	assets->swall = NULL;
	assets->wwall = NULL;
	assets->ewall = NULL;
	assets->floor = 0;
	assets->ceiling = 0;
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