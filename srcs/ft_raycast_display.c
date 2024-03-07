/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/07 15:09:59 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


/* ------------------------------- stripe_cast() -------------------------------- */
/*
**		dessine une stripe verticale en fonction de la hauteur du mur et des couleurs
**      du floor et du ceiling!
*/

void    stripe_cast(int x, t_mlx *data, int start, int end)
{
    int y;
    int pixel;

    y = 0;
    // printf("pos = (%f, %f)\n", data->pos->x, data->pos->y);
    // printf("start = %d, end = %d\n", start, end);
    while (y < WINHEIGHT)
    {
    	pixel = x + y * WINWIDTH;
        // printf("y = %d\n", y);
        if (y < start)
        {
    		data->raycasting.addr[pixel] = 0x77b6d1;
            // render_tile(&data->raycasting, (t_tile){x, y, 1, 1, 0xffff99});
            // printf("%d goes in start\n", y);
            // img_pix_put(&data->raycasting, x, y, 0x77b6d1);
        }
        else if (y > end)
        {
            // render_tile(&data->raycasting, (t_tile){x, y, 1, 1, 0x99ffff});
            // printf("%d goes in end\n", y);
    		data->raycasting.addr[pixel] = 0x8ed468;
        }
        else
        {
            // printf("%d goes in walls\n", y);
            if (data->sideHit == 1)
                // render_tile(&data->raycasting, (t_tile){x, y, 1, 1, 0xff99ff});
          		data->raycasting.addr[pixel] = 0x7672b0;
                // img_pix_put(&data->raycasting, x, y, 0x7672b0);
            else
          		data->raycasting.addr[pixel] = 0x9894d6;
                // render_tile(&data->raycasting, (t_tile){x, y, 1, 1, (0xff99ff / 2)});
                // img_pix_put(&data->raycasting, x, y, 0x9894d6);
        }
        y++;
    }
}

/* ------------------------------- wall_cast() -------------------------------- */
/*
**		calcule la hauteur du mur à afficher (lineheight) en fonction de sa distance
**      au plan du joueur (perpWallDist), et les points y ou le programme doit commencer
**      et arreter de dessiner le mur.
*/

void    wall_cast(int x, t_mlx *data)
{
    int lineheight;
    int end;
    int start;
    
    lineheight = 0;
    start = 0;
    end = 0;
    lineheight = (int)(WINHEIGHT / data->perpWallDist);
    start = WINHEIGHT / 2 - lineheight / 2;
    if (start < 0)
        start = 0;
    end = lineheight / 2 + WINHEIGHT / 2;
    if (end >= WINHEIGHT)
        end = WINHEIGHT - 1;
    stripe_cast(x, data, start, end);
}