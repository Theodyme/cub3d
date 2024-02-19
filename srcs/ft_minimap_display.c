/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/19 15:12:16 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render_flat_walls(t_mlx *vars)
{
	int	i;
	int	j;

	i = -1;
	while (vars->lvl->map[++i])
	{
		j = -1;
		while (vars->lvl->map[i][++j])
		{
			// printf("printing walls: checking position (%d, %d)\n", j, i);
			if (vars->lvl->map[i][j] == '1')
			{
				render_tile(&vars->img, (t_tile){(j * TILESIZE),
					(i * TILESIZE), TILESIZE, TILESIZE, 0x5DA69B});
			}
		}
	}
	return (0);
}

int	render_tile(t_img *img, t_tile tile)
{
	int		i;
	int		j;

	i = tile.y;
	while (i < tile.y + tile.height)
	{
		j = tile.x;
		while (j < tile.x + tile.width)
			img_pix_put(img, j++, i, tile.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

void	render_minimap(t_mlx *vars)
{
	render_background(&vars->img, 0xAACFCF, (vars->lvl->y * TILESIZE),
		(vars->lvl->x * TILESIZE));
	render_tile(&vars->img, (t_tile){(vars->player[0] * TILESIZE),
		(vars->player[1] * TILESIZE), TILESIZE, TILESIZE, 0xDE7955});
	render_flat_walls(vars);
}
