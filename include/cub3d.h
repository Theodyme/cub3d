/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:42:25 by flplace           #+#    #+#             */
/*   Updated: 2024/02/14 14:27:46 by theophane        ###   ########.fr       */
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


# define WHITESPACES "\t\r\v\f\n "
# define WINHEIGHT 800
# define WINWIDTH 1200
# define TILESIZE 20

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
    int width;
    int height;
    int color;
}	t_tile;

typedef struct s_parse
{
    char    **textures;
    int        len_textures;
    int        *rgb;
    char    **map;
    int        len_map;
}            t_parse;

typedef struct s_map
{
	char	**map;
	int		y;
	int		x;
}				t_map;

typedef struct s_data {
	void	*img;
}				t_data;

typedef struct s_assets {
	t_data	*nwall;
	t_data	*swall;
	t_data	*wwall;
	t_data	*ewall;
	t_data	*bg;
	t_data	*start;
}				t_assets;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		*lvl;
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
// UTILS

void    map_init();

// ****************************************************************************
// TITLE

#endif
