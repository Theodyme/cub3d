/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/03/15 09:36:29 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/utils.h"
# include "../mlx/mlx.h"
# include "colors.h"
# include "linux_keys.h"
# include "get_next_line.h"
# include "parsing.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WHITESPACES "\t\r\v\f\n "
# define WINHEIGHT 700
# define WINWIDTH 900
# define MOVE_SPEED 0.09777
# define ROT_SPEED 0.06522
# define TILESIZE 5

typedef struct s_img
{
	void		*mlx_img;
	int			*addr;
	int			bpp; /* bits per pixel */
	int			line_len;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct s_tile
{
	int			x;
	int			y;
	int			width;
	int			height;
	int			color;
}				t_tile;

typedef struct s_map
{
	char		**map;
	int			lenX;
	int			lenY;
}				t_map;

typedef struct s_assets
{
	t_img		*nwall;
	t_img		*swall;
	t_img		*wwall;
	t_img		*ewall;
	int			floor;
	int			ceiling;
}				t_assets;

typedef struct s_moves
{
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
}				t_moves;

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_vint
{
	int		x;
	int		y;
}				t_vint;

typedef struct s_draw
{
	int		lineheight;
	int		start;
	int		end;
}				t_draw;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_moves		*moves;
	int			sideHit;
	t_draw		*draw;
	t_img		minimap;
	t_img		raycasting;
	t_map		*lvl;
	t_vector	*pos;
	t_vint		*step;
	t_vint		*square;
	t_vector	*dir;
	t_vector	*plane;
	double		camerax;
	double		perpWallDist;
	double		time;
	double		oldTime;
	t_vector	*ray;
	t_vector	*delta;
	t_vector	*side;
	t_assets	*assets;
}				t_mlx;

/* ------------------------------- ft_key_hooks ----------------------------------- */

int		keyrelease_hook(int keycode, t_mlx *data);
int		keypress_hook(int keycode, t_mlx *data);

/* --------------------------------- ft_moves ----------------------------------- */

void	move_forward(t_mlx *data);
void	move_backward(t_mlx *data);
void	move_right(t_mlx *data);
void	move_left(t_mlx *data);
void	rotation(t_mlx *data);

/* ------------------------------- ft_data_handler -------------------------------- */

void	data_alloc(t_mlx *data);
void	data_init(t_mlx *data);
void	assets_init(t_assets *assets);
int		rgb_to_int(int r, int g, int b);
void	init_textures(t_parse *parse, t_mlx *data);

/* ------------------------------- ft_data_clear -------------------------------- */

void	data_freer(t_mlx *data);
void	lvl_freer(t_map *lvl);
void	clear_all(t_mlx *data);

/* ------------------------------- ft_minimap_display -------------------------------- */

void	img_pix_put(t_img *img, int x, int y, int color);
int		render_flat_walls(t_mlx *data);
int		render_tile(t_img *img, t_tile tile);
void	render_background(t_img *img, int color, int height, int width);
void	render_minimap(t_mlx *data);

/* ------------------------------- ft_minimap_update -------------------------------- */

int		strchr_charset(char *str, char *charset);
char	player_finder(t_mlx *data);

/* ------------------------------- ft_printers -------------------------------- */

void	map_printer(char **map, int y);

/* ------------------------------- ft_fetch_data -------------------------------- */

int 	map_cpy(t_parse *parse, t_mlx *data);
int		fetch_map_data(t_mlx *data, t_parse *parse);

/* ------------------------------- ft_init_window -------------------------------- */

int		destroy_win(t_mlx *data);
int		loop_process(t_mlx *data);
int		game_launcher(t_mlx *data);
int		data_builder(t_parse *parse, t_mlx *data);

/* ------------------------------- ft_raycasting -------------------------------- */

void    ray_calculator(int i, t_mlx *data);
void    delta_calculator(t_mlx *data);
void    side_calculator(t_mlx *data);
void    hitpoint_calculator(t_mlx *data);
void    main_process(t_mlx *data);

/* ------------------------------- ft_raycast_display -------------------------------- */

void    stripe_cast(int x, t_mlx *data, int start, int end);
void    wall_cast(int x, t_mlx *data);

void	init_textures(t_parse *parse, t_mlx *data);

#endif
