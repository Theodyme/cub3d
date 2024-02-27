/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/02/23 19:37:48 by theophane        ###   ########.fr       */
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
	int		lenX;
	int		lenY;
}				t_map;

typedef struct s_assets {
	void	*nwall;
	void	*swall;
	void	*wwall;
	void	*ewall;
}				t_assets;

typedef struct s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef struct s_square
{
	int		x;
	int 	y;
}				t_square;

typedef struct s_dir
{
	double	x;
	double	y;
}				t_dir;

typedef struct s_plane
{
	double	x;
	double	y;
}				t_plane;

typedef struct s_rayDir
{
	double	x;
	double	y;
}				t_rayDir;

typedef struct s_deltaDist
{
	double	x;
	double	y;
}				t_deltaDist;

typedef struct s_sideDist
{
	double	x;
	double	y;
}				t_sideDist;


typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			*ceiling;
	int			*floor;
	t_map		*lvl;
	t_parse		*parse;
	t_pos		*pos;
	t_square	*square;
	t_dir		*dir;
	t_plane		*plane;
	double		camerax;
	double		time;
	double		oldTime;
	t_rayDir	*rayDir;
	t_deltaDist	*delta;
	t_sideDist	*side;
	// t_assets	*assets;
}				t_mlx;

/* ------------------------------- ft_data_handler -------------------------------- */

void	data_alloc(t_mlx *data);
void	data_init(t_mlx *data);
void	data_freer(t_mlx *data);

/* ------------------------------- ft_minimap_display -------------------------------- */

void	img_pix_put(t_img *img, int x, int y, int color);
int		render_flat_walls(t_mlx *data);
int		render_tile(t_img *img, t_tile tile);
void	render_background(t_img *img, int color, int height, int width);
void	render_minimap(t_mlx *data);

/* ------------------------------- ft_minimap_update -------------------------------- */

int		strchr_charset(char *str, char *charset);
void	player_finder(t_mlx **data);

/* ------------------------------- ft_printers -------------------------------- */

void	map_printer(char **map, int y);

/* ------------------------------- ft_fetch_data -------------------------------- */

int map_cpy(t_parse *parse, t_mlx *data);
int		fetch_map_data(t_mlx *data, t_parse *parse);

/* ------------------------------- ft_init_window -------------------------------- */

int		loop_process(t_mlx *data);
int		game_launcher(t_mlx *data);
int		data_builder(t_parse *parse, t_mlx *data);

#endif
