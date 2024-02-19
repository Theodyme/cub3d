/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/19 15:11:42 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	destroy_win(t_mlx *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
}

void	init_testmap(t_mlx *vars)
{
	t_map	*lvl;

	lvl = malloc(sizeof(t_map));
	lvl->map = ft_calloc((9 + 1), sizeof(char *));
	for (int i = 0; i < 9; i++)
		lvl->map[i] = ft_calloc((17 + 2), sizeof(char));
	lvl->map[0] = ft_strdup("11111111111111111");
	lvl->map[1] = ft_strdup("10000000000000001");
	lvl->map[2] = ft_strdup("10000000100000001");
	lvl->map[3] = ft_strdup("10000000100010001");
	lvl->map[4] = ft_strdup("10000111100000001");
	lvl->map[5] = ft_strdup("10000000000000001");
	lvl->map[6] = ft_strdup("10000000000N00001");
	lvl->map[7] = ft_strdup("10000111000000001");
	lvl->map[8] = ft_strdup("11111111111111111");
	lvl->map[9] = '\0';
	lvl->x = 17;
	lvl->y = 8;
	vars->lvl = lvl;
	printf("lvl y = %d\nlvl x = %d\n", lvl->y, lvl->x);
	return ;
}

int	handle_no_event(t_mlx *vars)
{
	player_finder(&vars);
	printf("player is at (%d, %d)\n", vars->player[0], vars->player[1]);
	render_minimap(vars);
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
		return (1);
	vars->win = mlx_new_window(vars->mlx, WINWIDTH,
			WINHEIGHT, "cub3d");
	if (vars->win == NULL)
		return (1);
	vars->img.mlx_img = mlx_new_image(vars->mlx, WINWIDTH, WINHEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.mlx_img, &vars->img.bpp,
			&vars->img.line_len, &vars->img.endian);
	printf("img->bpp = %d\n", vars->img.bpp);
	mlx_loop_hook(vars->mlx, &handle_no_event, vars);
	mlx_hook(vars->win, 17, 1L << 5, destroy_win, vars);
	mlx_hook(vars->win, KeyPress, KeyPressMask, &key_hook, vars);
	mlx_loop(vars->mlx);
	return (0);
}

void	map_init(void)
{
	t_mlx	vars;

	init_testmap(&vars);
	game_launcher(&vars);
	return ;
}
