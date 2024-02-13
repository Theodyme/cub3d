/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/07 16:16:40 by theophane        ###   ########.fr       */
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
    lvl.map = ft_calloc(6, sizeof(char *));
    for (int i = 0; i < 4; i++)
        lvl.map[i] = ft_calloc((17 + 1), sizeof(char));
    lvl.map[0] = ft_strdup("1111111111111111");
    lvl.map[1] = ft_strdup("10000000000000001");
    lvl.map[2] = ft_strdup("10000000000000001");
    lvl.map[3] = ft_strdup("10000000000000001");
    lvl.map[4] = ft_strdup("10000000000000001");
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

int	handle_no_event(void *vars)
{
	(void)vars;
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
	mlx_loop_hook(vars->mlx, &handle_no_event, vars);
   	mlx_hook(vars->win, 17, 1L << 5, destroy_win, vars);
    mlx_hook(vars->win, KeyPress, KeyPressMask, &key_hook, vars);
	mlx_loop(vars->mlx);
	return (0);
}

void    map_init()
{
    t_mlx   vars;
    vars.mlx = mlx_init();
    if (vars.mlx == NULL)
		return ;
    init_testmap(&vars);
    vars.win = mlx_new_window(vars.mlx, (vars.lvl->x * TILESIZE),
			(TILESIZE * (vars.lvl->y) + 15), "cub3d minimap");
    if (vars.win == NULL)
	  	return ;
    game_launcher(&vars);
    return ;
}