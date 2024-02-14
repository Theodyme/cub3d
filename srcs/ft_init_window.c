/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/14 14:19:34 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	destroy_win(t_mlx *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
    exit(0);
}

void    init_testmap(t_mlx *vars)
{
    t_map   lvl;

    lvl.map = NULL;
    lvl.map = ft_calloc(9, sizeof(char *));
    for (int i = 0; i < 4; i++)
        lvl.map[i] = ft_calloc((17 + 1), sizeof(char));
    lvl.map[0] = ft_strdup("1111111111111111");
    lvl.map[1] = ft_strdup("10000000000000001");
    lvl.map[2] = ft_strdup("1000000010000001");
    lvl.map[3] = ft_strdup("10000000100000001");
    lvl.map[4] = ft_strdup("10000111100000001");
    lvl.map[5] = ft_strdup("10000000000000001");
    lvl.map[6] = ft_strdup("10000000000000001");
    lvl.map[7] = ft_strdup("10000000000000001");
    lvl.map[8] = ft_strdup("1111111111111111");
    lvl.y = 8;
    lvl.x = 17;
    vars->lvl = &lvl;
    printf("lvl y = %d\nlvl x = %d\n", lvl.y, lvl.x);
    return ;
}
void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;
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

int render_tile(t_img *img, t_tile tile)
{
    int	i;
    int j;

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
void	render_background(t_img *img, int color)
{
    int	i;
    int	j;

    i = 0;
    while (i < WINHEIGHT)
    {
        j = 0;
        while (j < WINWIDTH)
        {
            img_pix_put(img, j++, i, color);
        }
        ++i;
    }
}

int	handle_no_event(t_mlx *vars)
{
	render_background(&vars->img, 0xFFFFFF);
	render_tile(&vars->img, (t_tile){0, 0, TILESIZE, TILESIZE, 0xFF00});
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.mlx_img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_mlx *vars)
{
	if (keycode == XK_Escape)
		destroy_win(vars);
	return (0);
}

int	game_launcher(t_mlx *vars)
{
    vars->mlx = mlx_init();
    if (vars->mlx == NULL)
		return 1;
	vars->win = mlx_new_window(vars->mlx, WINWIDTH,
			WINHEIGHT, "cub3d");
    if (vars->win == NULL)
	  	return (1);
	vars->img.mlx_img = mlx_new_image(vars->mlx, WINWIDTH, WINHEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.mlx_img, &vars->img.bpp, &vars->img.line_len, &vars->img.endian);
    printf("img->bpp = %d\n", vars->img.bpp);
	mlx_loop_hook(vars->mlx, &handle_no_event, vars);
   	mlx_hook(vars->win, 17, 1L << 5, destroy_win, vars);
    mlx_hook(vars->win, KeyPress, KeyPressMask, &key_hook, vars);
	mlx_loop(vars->mlx);
	return (0);
}

void    map_init()
{
    t_mlx   vars;
    init_testmap(&vars);
    game_launcher(&vars);
    return ;
}
