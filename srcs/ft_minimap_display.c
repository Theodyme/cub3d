/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/08 16:16:13 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- img_pix_put() ---------------------------------- */
/*
**		c'est l'équivalent du mlx_pixel_put() de Abrabant (cf tuto sur google).
**		je me mens peut être à moi-même, mais je compte comprendre en détail
**		comment elle fonctionne dès qu'on aura un raycasting qui tourne et un
**		peu de temps. ça m'embête d'avoir un truc que j'ai pas codé et que je
**		comprends pas complètement dans mon projet.
**
**		dans les grandes lignes, c'est une fonction qui écrit des pixels aux
**		coordonnées x et y, de la couleur color. elle prend en compte les bits
**		par pixel, la taille de ton image, et si ton système lit les bits de
**		gauche à droite ou de droite à gauche.
*/

// void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char	*pixel;
// 	int		i;

// 	(void)x;
// 	(void)y;
// 	pixel = null;
// 	i = img->bpp - 8;
// 	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	while (i >= 0)
// 	{
// 		/* big endian, MSB is the leftmost bit */
// 		if (img->endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		/* little endian, LSB is the leftmost bit */
// 		else
// 			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
// 		i -= 8;
// 	}
// }

/* ------------------------------- render_*() ---------------------------------- */
/*
**		render des trucs avec un équivalent du mlx_pixel_put()!
**		pour rappel, ces fonctions n'affichent pas directement, elles écrivent
**		sur l'image avant qu'on ne l'envoie au display. si tu fais un img_pix_put()
**		sans put_img_to_window ensuite, rien ne s'affichera.
*/

// int	render_flat_walls(t_mlx *data)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (data->lvl->map[++i])
// 	{
// 		j = -1;
// 		while (data->lvl->map[i][++j])
// 		{
// 			if (data->lvl->map[i][j] == '1')
// 			{
// 				render_tile(&data->minimap, (t_tile){(j * TILESIZE),
// 					(i * TILESIZE), TILESIZE, TILESIZE, 0x5DA69B});
// 			}
// 		}
// 	}
// 	return (0);
// }

// int	render_tile(t_img *img, t_tile tile)
// {
// 	int		i;
// 	int		j;

// 	i = tile.y;
// 	while (i < tile.y + tile.height)
// 	{
// 		j = tile.x;
// 		while (j < tile.x + tile.width)
// 			img_pix_put(img, j++, i, tile.color);
// 		++i;
// 	}
// 	return (0);
// }

// void	render_background(t_img *img, int color, int width, int height)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while (j < width)
// 		{
// 			img_pix_put(img, j++, i, color);
// 		}
// 		++i;
// 	}
// }

/* ------------------------------- render_minimap() ---------------------------------- */
/*
**		rassemble toutes les fonctions de render, dans l'ordre:
**		- le fond
**		- le player
**		- les murs
**		/!\ l'ordre dans lequel tu les écris va affecter quel pixel prendra la priorité sur l'autre!
*/

// void	render_minimap(t_mlx *data)
// {
// 	render_background(&data->minimap, 0xAACFCF, (data->lvl->lenX * TILESIZE),
// 		(data->lvl->lenY * TILESIZE));
// 	render_tile(&data->minimap, (t_tile){(data->square->x * TILESIZE),
// 		(data->square->y * TILESIZE), TILESIZE, TILESIZE, 0xDE7955});
// 	render_flat_walls(data);
// }
