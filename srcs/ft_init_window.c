/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/27 16:18:52 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- destroy_window() ---------------------------------- */
/*
**		appelée dans le hook de la touche échap et de la fermeture de la fenêtre.
**		assez straightforward: elle détruit l'image et le display, puis exit.
**
**		il faudra peut être ajouter des étapes de free() là dedans une fois qu'on
**		aura des structures plus définitives!
*/

int	destroy_win(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->assets);
	free(data->lvl);
	exit(0);
}

/* ------------------------------- init_testmap() ---------------------------------- */
/*
**		écrit une map en dur et la balance dans data->lvl en affichant bien la size.
**
**		kill it with fire.
*/

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	init_textures(t_parse *parse, t_mlx *data)
{
	int width;
	int height;

	width = WINWIDTH;
	height = WINHEIGHT;
	data->assets = malloc(sizeof(t_assets));
	if (data->assets == NULL)
		return (printf("Error\nMalloc\n"), ft_free_map(parse), exit(0));
	assets_init(data->assets);
	printf("parse->n_id = %d\n", parse->n_id);
	printf("parse->textures[n_id] = [%s]\n", parse->textures[parse->n_id]);
	// printf("data->assets->nwall = [%p]\n", data->assets->nwall);
	data->assets->nwall = mlx_xpm_file_to_image(data->mlx,
												parse->textures[parse->n_id],
												&width,
												&height);
	data->assets->swall = mlx_xpm_file_to_image(data->mlx,
												parse->textures[parse->s_id],
												&width,
												&height);
	data->assets->wwall = mlx_xpm_file_to_image(data->mlx,
												parse->textures[parse->w_id],
												&width,
												&height);
	data->assets->ewall = mlx_xpm_file_to_image(data->mlx,
												parse->textures[parse->e_id],
												&width,
												&height);
	data->assets->floor = rgb_to_int(parse->rgb[0], parse->rgb[1],
			parse->rgb[2]);
	data->assets->ceiling = rgb_to_int(parse->rgb[3], parse->rgb[4],
			parse->rgb[5]);
	printf("nwall = %p\nswall = %p\nwwall = %p\n", data->assets->nwall,
			data->assets->swall, data->assets->wwall);
}

/* --------------------------- handle_no_event() ------------------------------- */
/*
**		fonction appelée par mlx_loop_hook(),
**		gère le comportement par défaut s'il n'y a pas d'action particulière.
**		en l'état,
			il cherche la position du joueur et render la minimap en conséquence.
**
**		étant donné que la structure de la map ne bouge pas,
			à voir si on ne pourrait pas
**		juste mettre l'affichage du joueur là dedans et l'affichage de la map en dehors de
**		la boucle pour nous sauver de la perf.
**
**		de la façon dont j'ai géré l'affichage,
			on écrit des pixels directement dans une image
**		et on l'envoie ensuite à chaque frame à travers mlx_put_image_to_window().
*/

int	loop_process(t_mlx *data)
{
	player_finder(&data);
	render_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}

/* ------------------------------- key_hook() ---------------------------------- */
/*
**		parle d'elle même; est appelée dans mlx_hook() pour binder des touches à des actions.
**		actuellement, j'ai simplement ajouté la touche echap!
*/

int	key_hook(int keycode, t_mlx *data)
{
	if (keycode == XK_Escape)
		return (lvl_freer(data->lvl), destroy_win(data), exit(0), 0);
	return (0);
}

/* ----------------------------- game launcher() ------------------------------- */
/*
**		initialise tous les éléments de data utiles pour faire tourner la MLX,
			à savoir:
**		- data->mlx : le pointeur mlx *
**		- data->win : le pointeur vers la window ouverte avec la mlx
**		- data->img.mlx_img : le pointeur vers une nouvelle image,
			actuellement utilisée pour la minimap
**								(peut être à décaler ailleurs si on en fait une autre pour la projection 3D)
**		- data->img.addr : l'adresse de cette nouvelle image
**		gère les hooks avant de lancer la loop.
*/

int	game_launcher(t_mlx *data)
{
	// data->mlx = mlx_init();
	// if (data->mlx == NULL)
	// 	return (1);
	// init_textures(data);
	data->win = mlx_new_window(data->mlx, WINWIDTH, WINHEIGHT, "cub3d");
	if (data->win == NULL)
		return (1);
	data->img.mlx_img = mlx_new_image(data->mlx, WINWIDTH, WINHEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	mlx_loop_hook(data->mlx, &loop_process, data);
	mlx_hook(data->win, 17, 1L << 5, destroy_win, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, &key_hook, data);
	mlx_loop(data->mlx);
	return (0);
}

/* ------------------------------- map_init() -------------------------------- */
/*
**		initialise la structure de données data et lance le game_launcher.
**		voir si ça peut pas être décalé dans game_launcher directement après avoir viré init_testmap.
*/

int	data_builder(t_parse *parse, t_mlx *data)
{		
	data_init(data);
	if (data == NULL)
		return (1);
	if (fetch_map_data(data, parse) == 1)
		return (1);
	return (0);
}

