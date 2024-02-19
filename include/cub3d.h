/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/02/19 17:04:25 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/keysymdef.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "colors.h"
# include "../lib/utils.h"
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include "parsing.h"

# define WHITESPACES "\t\r\v\f\n "
# define WINHEIGHT 800
# define WINWIDTH 1200
# define TILESIZE 5

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_tile
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_tile;

typedef struct s_map
{
	char	**map;
	int		y;
	int		x;
}				t_map;

typedef struct s_asset_img {
	void	*img;
}				t_asset_img;

typedef struct s_assets {
	t_asset_img	*nwall;
	t_asset_img	*swall;
	t_asset_img	*wwall;
	t_asset_img	*ewall;
	t_asset_img	*bg;
	t_asset_img	*start;
}				t_assets;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		*lvl;
	t_parse		*parse;
	int			player[2];
	// t_assets	*assets;
}				t_mlx;

/*
	- player pos x
	- player pos y
	- the ray should be positive
	- the wall should be between 0 to x

	- a function that find the player position
	- handle multiple collision points

	for movements;
	(player pos + player dir) * movespeed
*/

// ****************************************************************************
// MINIMAP DISPLAY

void	img_pix_put(t_img *img, int x, int y, int color);
int		render_flat_walls(t_mlx *data);
int		render_tile(t_img *img, t_tile tile);
void	render_background(t_img *img, int color, int height, int width);
void	render_minimap(t_mlx *data);

// ****************************************************************************
// PRINTERS

void	map_printer(char **map, int y);

// ****************************************************************************
// MOVEMENTS

int		strchr_charset(char *str, char *charset);
void	player_finder(t_mlx **data);

// ****************************************************************************
// INIT_WINDOW

void	map_init(t_parse *parse);

// ****************************************************************************
// TITLE

#endif
