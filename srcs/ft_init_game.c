/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/18 12:21:04 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* -------------------- move_update() ----------------- */
/*
**		applique les mouvements.
*/

void	move_update(t_mlx *data)
{
	if (data->moves->forward)
		move_forward(data);
	if (data->moves->backward)
		move_backward(data);
	if (data->moves->left)
		move_left(data);
	if (data->moves->right)
		move_right(data);
	if (data->moves->rotate_left || data->moves->rotate_right)
		rotation(data);
	return ;
}
/* --------------------- main_process() ----------------------- */
/*
**		regroupe toutes les fonctions nécessaires
        pour effectuer les calculs des data,
**      dans une boucle qui parcourt l'écran horizontalement,
        afin de faire ces calculs
**      pour chaque pixel sur l'axe Y.
*/

void	main_process(t_mlx *data)
{
	int	x;

	x = 0;
	while (x < WINWIDTH)
	{
		data->square->x = (int)data->pos->x;
		data->square->y = (int)data->pos->y;
		ray_calculator(x, data);
		delta_calculator(data);
		side_calculator(data);
		hitpoint_calculator(data);
		wall_cast(x, data);
		x++;
	}
}

/* ---------------- loop_process() ---------------------- */
/*
**		process de la lx loop: update l'affichage en
**		fonction des mouvements et lance le raycasting.
**		affiche ensuite l'image sur la fenetre.
*/

int	loop_process(t_mlx *data)
{
	move_update(data);
	main_process(data);
	mlx_put_image_to_window(data->mlx, data->win, data->raycasting.mlx_img, 0,
		0);
	return (0);
}

/* -------------------- game launcher() ------------------------ */
/*
**	initialise tous les éléments de data utiles pour faire tourner la MLX,
		à savoir:
**		- data->mlx : le pointeur mlx *
**		- data->win : le pointeur vers la window ouverte avec la mlx
**		- data->raycasting.mlx_img : le pointeur vers une nouvelle image,
		actuellement utilisée pour la minimap
**		(peut être à décaler ailleurs si on en fait une autre pour la projection 3D)
**		- data->raycasting.addr : l'adresse de cette nouvelle image
**		gère les hooks avant de lancer la loop.
*/

int	game_launcher(t_mlx *data)
{
	data->win = mlx_new_window(data->mlx, WINWIDTH, WINHEIGHT, "cub3d");
	if (data->win == NULL)
		return (1);
	data->raycasting.mlx_img = mlx_new_image(data->mlx, WINWIDTH, WINHEIGHT);
	data->raycasting.addr = (int *)mlx_get_data_addr(data->raycasting.mlx_img,
			&data->raycasting.bpp, &data->raycasting.line_len,
			&data->raycasting.endian);
	mlx_loop_hook(data->mlx, &loop_process, data);
	mlx_hook(data->win, 17, 1L << 5, escape, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &keypress_hook, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &keyrelease_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
/* ------------------ data_builder() ------------------- */
/*
**		initialise la structure de données data et
			lance le game_launcher.
**		voir si ça peut pas être décalé dans
		game_launcher directement après avoir viré init_testmap.
*/

int	data_builder(t_parse *parse, t_mlx *data)
{
	char	orientation;

	data_init(data);
	if (data == NULL)
		return (1);
	if (fetch_map_data(data, parse) == 1)
		return (1);
	orientation = player_finder(data);
	orientation_finder(data, orientation);
	data->pos->x = data->square->x + 0.5;
	data->pos->y = data->square->y + 0.5;
	return (0);
}
