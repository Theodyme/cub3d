/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/15 19:07:57 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ----------------------- stripe_cast() ------------------------- */
/*
**		dessine une stripe verticale en fonction de la hauteur du mur
**		et des couleurs	du floor et du ceiling!
*/

void	y_cast_loop(int x, t_mlx *data, t_img *asset, t_vint *tex)
{
	int		y;
	int		pixel;
	double	step;
	double	texpos;

	step = 1.0 * asset->height / data->draw->lineheight;
	texpos = (data->draw->start - 1 - WINHEIGHT / 2
			+ data->draw->lineheight / 2) * step;
	y = 0;
	while (y < WINHEIGHT)
	{
		pixel = x + y * WINWIDTH;
		if (y < data->draw->start)
			data->raycasting.addr[pixel] = data->assets->ceiling;
		else if (y > data->draw->end)
			data->raycasting.addr[pixel] = data->assets->floor;
		else
		{
			tex->y = (int)texpos & (asset->height - 1);
			texpos += step;
			data->raycasting.addr[pixel] = asset->addr[asset->height
				* tex->y + tex->x];
		}
		y++;
	}
}

void	get_texture_x(t_mlx *data, t_vint *tex, t_img *asset)
{
	double	hit_x;

	hit_x = 0;
	if (data->sideHit == 0)
		hit_x = (data->pos->y + data->perpWallDist * data->ray->y);
	else
		hit_x = (data->pos->x + data->perpWallDist * data->ray->x);
	hit_x -= floor((hit_x));
	tex->x = (int)(hit_x * (double)(asset->width));
	if (data->sideHit == 0 && data->ray->x < 0)
		tex->x = asset->width - tex->x - 1;
	if (data->sideHit == 1 && data->ray->y > 0)
		tex->x = asset->width - tex->x - 1;
}

t_img	*get_orientation(t_mlx *data)
{
	if (data->ray->x < 0)
	{
		if (data->sideHit == 0)
			return (data->assets->wwall);
		else if (data->ray->y < 0)
			return (data->assets->nwall);
		else
			return (data->assets->swall);
	}
	else
	{
		if (data->sideHit == 0)
			return (data->assets->ewall);
		else if (data->ray->y > 0)
			return (data->assets->swall);
		else
			return (data->assets->nwall);
	}
}

void	lineheight_calculator(t_mlx *data, t_draw *draw)
{
	draw->lineheight = (int)(WINHEIGHT / data->perpWallDist);
	draw->start = WINHEIGHT / 2 - draw->lineheight / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = draw->lineheight / 2 + WINHEIGHT / 2;
	if (draw->end >= WINHEIGHT)
		draw->end = WINHEIGHT - 1;
}

/* -------------------- wall_cast() ------------------------ */
/*
**		calcule la hauteur du mur à afficher (lineheight)
**		en fonction de sa distance au plan du joueur
**		(perpWallDist), et les points y ou le programme
**		doit commencer et arreter de dessiner le mur.
*/

void	wall_cast(int x, t_mlx *data)
{
	t_img	*asset;
	t_vint	*tex;

	tex = malloc(sizeof(t_vint));
	tex->x = 0;
	tex->y = 0;
	lineheight_calculator(data, data->draw);
	asset = get_orientation(data);
	get_texture_x(data, tex, asset);
	y_cast_loop(x, data, data->draw, asset, tex);
	free(tex);
}
