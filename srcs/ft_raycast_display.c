/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/13 20:06:31 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- stripe_cast() -------------------------------- */
/*
**		dessine une stripe verticale en fonction de la hauteur du mur et des couleurs
**      du floor et du ceiling!
*/

void    y_cast_loop(int x, t_mlx *data, t_draw *draw, t_img *asset, t_vint *tex)
{
    int y;
    int pixel;
    int step;
    int texPos;

    step = 1.0 * asset->height / draw->lineheight;
    // step = 0;
    texPos = (draw->start - WINHEIGHT / 2 + draw->lineheight / 2) * step;
    y = 0;
    while (y < WINHEIGHT)
    {
    	pixel = x + y * WINWIDTH;
        if (y < draw->start)
    		data->raycasting.addr[pixel] = 0x77b6d1;
        else if (y > draw->end)
    		data->raycasting.addr[pixel] = 0x8ed468;
        else
        {
            texPos = tex->x + (int)tex->y * asset->width;
            data->raycasting.addr[pixel] = asset->addr[texPos];
            tex->y += step;
            if (data->sideHit == 1)
                data->raycasting.addr[pixel] = asset->addr[texPos];
            // printf("casting [%d, %d]\n", x, y);
        }
        y++;
    }
}

void    get_texture_x(t_mlx *data, t_vint *tex, t_img *asset)
{
    double hit_x;

    hit_x = 0;
    // calcul de l'endroit où on a touché sur le mur:
    if (data->sideHit == 0)
        hit_x = (int)(data->pos->y + data->perpWallDist * data->ray->y);
    else
        hit_x = (int)(data->pos->x + data->perpWallDist * data->ray->x);
    hit_x -= floor((hit_x));
    tex->x = (int)(hit_x * (double)(asset->width)); 
    // // fix symétrie horizontale:
    if ((data->sideHit == 0 && data->ray->x > 0) || (data->sideHit == 1 && data->ray->y < 0))
        tex->x = asset->width - tex->x - 1;
}

t_img	*get_orientation(t_mlx *data)
{
	if (data->ray->x < 0)
	{
		if (data->sideHit == 0)
			return (data->assets->nwall);
		else if (data->ray->y < 0)
			return (data->assets->wwall);
		else
			return (data->assets->ewall);
	}
	else
	{
		if (data->sideHit == 0)
			return (data->assets->swall);
		else if (data->ray->y > 0)
			return (data->assets->ewall);
		else
			return (data->assets->wwall);
	}
}

void lineheight_calculator(t_mlx *data, t_draw *draw)
{
    draw->lineheight = (int)(WINHEIGHT / data->perpWallDist);
    draw->start = WINHEIGHT / 2 - draw->lineheight / 2;
    if (draw->start < 0)
        draw->start = 0;
    draw->end = draw->lineheight / 2 + WINHEIGHT / 2;
    if (draw->end >= WINHEIGHT)
        draw->end = WINHEIGHT - 1;
}

// /* ------------------------------- wall_cast() -------------------------------- */
// /*
// **		calcule la hauteur du mur à afficher (lineheight) en fonction de sa distance
// **      au plan du joueur (perpWallDist), et les points y ou le programme doit commencer
// **      et arreter de dessiner le mur.
// */

void    wall_cast(int x, t_mlx *data)
{
    t_img   *asset;
    t_vint *tex;

    tex = malloc(sizeof(t_vint));
    tex->x = 0;
    tex->y = 0;
    lineheight_calculator(data, data->draw);
    asset = get_orientation(data);
    // printf("tex->x = %d\n", tex->x);
    // get_texture_x(data, tex, asset);
    // printf("after set tex->x = %d\n", tex->x);

    printf("tex->x = %d\n", tex->x);

    double hit_x;

    hit_x = 0;
    // calcul de l'endroit où on a touché sur le mur:
    if (data->sideHit == 0)
        hit_x = (data->pos->y + data->perpWallDist * data->ray->y);
    else
        hit_x = (data->pos->x + data->perpWallDist * data->ray->x);

    printf("hit_x = %f\n", hit_x);

    hit_x -= floor((hit_x));
    
    printf("after set hit_x = %f\n", hit_x);
    
    tex->x = (int)(hit_x * (double)(asset->width));
    
    // // fix symétrie horizontale:
    if (data->sideHit == 0 && data->ray->x > 0)
        tex->x = asset->width - tex->x - 1;
    if (data->sideHit == 1 && data->ray->y < 0)
        tex->x = asset->width - tex->x - 1;


    // y_cast_loop(x, data, data->draw, asset, tex);
    int y;
    int pixel;
    double step;
    double texPos;
    
    step = 0;

    printf("step = %f\n", step);

    step = 1.0 * asset->height / data->draw->lineheight;

    printf("after step = %f\n", step);

    texPos = (data->draw->start - WINHEIGHT / 2 + data->draw->lineheight / 2) * step;
   
    printf("texPos = %f\n", texPos);
   
    y = 0;
    while (y < WINHEIGHT)
    {
    	pixel = x + y * WINWIDTH;
        if (y < data->draw->start)
    		data->raycasting.addr[pixel] = 0x77b6d1;
        else if (y > data->draw->end)
    		data->raycasting.addr[pixel] = 0x8ed468;
        else
        {
            tex->y = (int)texPos & (asset->height - 1);
            // texPos = tex->x + (int)tex->y * asset->width;
            texPos += step;
            data->raycasting.addr[pixel] = asset->addr[asset->height * tex->y + tex->x];
            // tex->y += step;
            // if (data->sideHit == 1)
                // data->raycasting.addr[pixel] = (data-;
            // printf("casting [%d, %d]\n", x, y);
        }
        y++;
    }
    free(tex);
}
