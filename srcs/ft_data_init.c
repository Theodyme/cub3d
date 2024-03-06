/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/06 17:30:17 by theophane        ###   ########.fr       */
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
		data->moves = malloc(sizeof(t_moves));
		data->pos = malloc(sizeof(t_vector));
		data->step = malloc(sizeof(t_step));
		data->square = malloc(sizeof(t_square));
		data->dir = malloc(sizeof(t_vector));
		data->plane = malloc(sizeof(t_vector));
		data->ray = malloc(sizeof(t_vector));
		data->delta = malloc(sizeof(t_vector));
		data->side = malloc(sizeof(t_vector));
	}
	if (!(data->pos) || !(data->step) || !(data->square) || !(data->dir) || !(data->plane) || !(data->ray) || !(data->delta) || !(data->side))
		data_freer(data);
	return ;
}

/* ------------------------------- moves_init() -------------------------------- */
/*
**		initialise les structures d'assets.
*/

void	moves_init(t_moves *moves)
{
	moves->backward = 0;
	moves->forward = 0;
	moves->left = 0;
	moves->right = 0;
	moves->rotate_left = 0;
	moves->rotate_right = 0;	
}

/* ------------------------------- data_init() -------------------------------- */
/*
**		initialise les structures de données.
*/

void	data_init(t_mlx *data)
{
	data_alloc(data);
	moves_init(data->moves);
	data->pos->x = 0;
	data->pos->y = 0;
	data->step->x = 0;
	data->step->y = 0;
	data->square->x = 0;
	data->square->y = 0;
	data->dir->x = 0;
	data->dir->y = 0;
	data->plane->x = 0;
	data->plane->y = 0;
	data->camerax = 0;
	data->time = 0;
	data->oldTime = 0;
	data->ray->x = 0;
	data->ray->y = 0;
	data->delta->x = 0;
	data->delta->y = 0;
	data->side->x = 0;
	data->side->y = 0;
	return ;
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
