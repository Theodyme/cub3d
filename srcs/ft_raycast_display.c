/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/17 20:53:26 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ----------------------- stripe_cast() ------------------------- */
/*
**		dessine une stripe verticale en fonction de la hauteur du mur
**		et des couleurs	du floor et du ceiling!
*/

void	y_cast_loop(int x, t_mlx *data, t_img *asset, t_vector *ratio)
{
	int		y;
	int		pixel;
	// double	step;
    double     block;
    double     pixel_y;
    double     pixtex;
	// double	texpos;
    
    block = data->draw->end - data->draw->start;
	// step = 1.0 * asset->height / data->draw->lineheight;
	// texpos = (data->draw->start - 1 - WINHEIGHT / 2
			// + data->draw->lineheight / 2) * step;
	y = 0;
	while (y < WINHEIGHT)
	{
        // printf("y, end, start : %d, %d, %d\n", y, data->draw->end, data->draw->start);
        // printf("block : %f\n", block);
        ratio->y = (y - data->draw->start) / block;
        // printf("ratio-y : %f\n", ratio->y);
        pixel_y = ((double)asset->height * ratio->y);
        // printf("pixel-y : %f\n", pixel_y);
		pixel = x + y * WINWIDTH;
        pixtex = ratio->x + pixel_y * (double)asset->height;
        // printf("pixtex : %f\n", pixtex);
		if (y < data->draw->start)
			data->raycasting.addr[pixel] = data->assets->ceiling;
		else if (y > data->draw->end)
			data->raycasting.addr[pixel] = data->assets->floor;
		else
		{
			// tex->y = (int)texpos & (asset->height - 1);
			// texpos += step;
			data->raycasting.addr[pixel] = asset->addr[(int)pixtex];
            // data->raycasting.addr[pixel] = asset->addr[pixel_y];
		}
		y++;
	}
}

void	get_texture_x(t_mlx *data, t_vector *ratio, t_img *asset)
{
	double	hit_x;

	hit_x = 0;
	if (data->sideHit == 0)
		hit_x = (data->pos->y + data->pwdist * data->ray->y);
	else
		hit_x = (data->pos->x + data->pwdist * data->ray->x);
	hit_x -= floor((hit_x));
	ratio->x = (hit_x * (double)(asset->width));
	if (data->sideHit == 0 && data->ray->x < 0)
		ratio->x = asset->width - ratio->x - 1;
	if (data->sideHit == 1 && data->ray->y > 0)
		ratio->x = asset->width - ratio->x - 1;
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
	draw->lineheight = (int)(WINHEIGHT / data->pwdist);
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
**		(pwdist), et les points y ou le programme
**		doit commencer et arreter de dessiner le mur.
*/

void	wall_cast(int x, t_mlx *data)
{
	t_img	*asset;
	t_vector	*ratio;

	ratio = malloc(sizeof(t_vector));
	ratio->x = 0;
	ratio->y = 0;
	lineheight_calculator(data, data->draw);
	asset = get_orientation(data);
	get_texture_x(data, ratio, asset);
	y_cast_loop(x, data, asset, ratio);
	free(ratio);
}