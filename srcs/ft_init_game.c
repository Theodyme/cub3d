/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/08 20:42:48 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- move_update() -------------------------------- */
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


/* --------------------------- loop_process() ------------------------------- */
/*
**		fonction appelée par mlx_loop_hook(),
**		gère le comportement par défaut s'il n'y a pas d'action particulière.
**		en l'état, il cherche la position du joueur et render la minimap en conséquence.
**
**		étant donné que la structure de la map ne bouge pas, à voir si on ne pourrait pas
**		juste mettre l'affichage du joueur là dedans et l'affichage de la map en dehors de
**		la boucle pour nous sauver de la perf.
**
**		de la façon dont j'ai géré l'affichage, on écrit des pixels directement dans une image
**		et on l'envoie ensuite à chaque frame à travers mlx_put_image_to_window().
*/

int	loop_process(t_mlx *data)
{
	// player_finder(&data);
	// data->pos->x = data->square->x + 0.5;
	// data->pos->y = data->square->y + 0.5;
	move_update(data);
	// render_minimap(data);
	// mlx_put_image_to_window(data->mlx, data->win, data->minimap.mlx_img, 0, 0);
	main_process(data);
	mlx_put_image_to_window(data->mlx, data->win, data->raycasting.mlx_img, 0, 0);
	return (0);
}

/* ----------------------------- game launcher() ------------------------------- */
/*
**		initialise tous les éléments de data utiles pour faire tourner la MLX, à savoir:
**		- data->mlx : le pointeur mlx *
**		- data->win : le pointeur vers la window ouverte avec la mlx
**		- data->raycasting.mlx_img : le pointeur vers une nouvelle image, actuellement utilisée pour la minimap
**								(peut être à décaler ailleurs si on en fait une autre pour la projection 3D)
**		- data->raycasting.addr : l'adresse de cette nouvelle image
**		gère les hooks avant de lancer la loop.
*/

int	game_launcher(t_mlx *data)
{
	data->win = mlx_new_window(data->mlx, WINWIDTH, WINHEIGHT, "cub3d");
	if (data->win == NULL)
		return (1);
	data->minimap.mlx_img = mlx_new_image(data->mlx, WINWIDTH, WINHEIGHT);
	data->minimap.addr = (int *)mlx_get_data_addr(data->minimap.mlx_img, &data->minimap.bpp,
			&data->minimap.line_len, &data->minimap.endian);
	data->raycasting.mlx_img = mlx_new_image(data->mlx, WINWIDTH, WINHEIGHT);
	data->raycasting.addr = (int *)mlx_get_data_addr(data->raycasting.mlx_img, &data->raycasting.bpp,
			&data->raycasting.line_len, &data->raycasting.endian);
	mlx_loop_hook(data->mlx, &loop_process, data);
	mlx_hook(data->win, 17, 1L << 5, destroy_win, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &keypress_hook, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &keyrelease_hook, data);
	mlx_loop(data->mlx);
	return (0);
}

/* ------------------------------- data_builder() -------------------------------- */
/*
**		initialise la structure de données data et lance le game_launcher.
**		voir si ça peut pas être décalé dans game_launcher directement après avoir viré init_testmap.
*/

int	orientation_finder(t_mlx *data, char c)
{
	if (c == 'N')
	{
		data->dir->x = 0;
		data->dir->y = -1;
		data->plane->x = -0.66;
		data->plane->y = 0;
	}
	else if (c == 'S')
	{
		data->dir->x = 0;
		data->dir->y = 1;
		data->plane->x = 0.66;
		data->plane->y = 0;
	}
	else if (c == 'W')
	{
		data->dir->x = 1;
		data->dir->y = 0;
		data->plane->x = 0;
		data->plane->y = -0.66;
	}
	else if (c == 'E')
	{
		data->dir->x = -1;
		data->dir->y = 0;
		data->plane->x = 0;
		data->plane->y = 0.66;
	}
	return (0);
}

/* ------------------------------- data_builder() -------------------------------- */
/*
**		initialise la structure de données data et lance le game_launcher.
**		voir si ça peut pas être décalé dans game_launcher directement après avoir viré init_testmap.
*/

int	data_builder(t_parse *parse, t_mlx *data)
{
	char orientation;

	data_init(data);
	if (data == NULL)
		return (1);
	if (fetch_map_data(data, parse) == 1)
		return (1);
	orientation = player_finder(&data);
	orientation_finder(data, orientation);
	data->pos->x = data->square->x + 0.5;
	data->pos->y = data->square->y + 0.5;
	return (0);
}

