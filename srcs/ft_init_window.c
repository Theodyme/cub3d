/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/22 15:30:47 by mderkaou         ###   ########.fr       */
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

void	init_testmap(t_mlx *data, t_parse *parse)
{
	t_map	*lvl;

	lvl = malloc(sizeof(t_map));
	if (lvl == NULL)
		return (printf("Error\nMalloc\n"), exit(0));
	lvl->map = parse->map;
	lvl->x = parse->max_len;
	lvl->y = parse->len_map;
	data->lvl = lvl;
	data->parse = parse;
	printf("lvl y = %d\nlvl x = %d\n", lvl->y, lvl->x);
	return ;
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	init_textures(t_mlx *data)
{
	data->assets = malloc(sizeof(t_assets));
	data->assets->width = WINWIDTH;
	data->assets->height = WINHEIGHT;
	if (data->assets == NULL)
		return (printf("Error\nMalloc\n"), ft_free_map(data->parse), exit(0));
	data->assets->nwall = mlx_xpm_file_to_image(data->mlx,
												data->parse->textures[data->parse->n_id],
												&data->assets->width,
												&data->assets->height);
	data->assets->swall = mlx_xpm_file_to_image(data->mlx,
												data->parse->textures[data->parse->s_id],
												&data->assets->width,
												&data->assets->height);
	data->assets->wwall = mlx_xpm_file_to_image(data->mlx,
												data->parse->textures[data->parse->w_id],
												&data->assets->width,
												&data->assets->height);
	data->assets->ewall = mlx_xpm_file_to_image(data->mlx,
												data->parse->textures[data->parse->e_id],
												&data->assets->width,
												&data->assets->height);
	data->assets->floor = rgb_to_int(data->parse->rgb[0], data->parse->rgb[1],
			data->parse->rgb[2]);
	data->assets->ceiling = rgb_to_int(data->parse->rgb[3], data->parse->rgb[4],
			data->parse->rgb[5]);
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

int	handle_no_event(t_mlx *data)
{
	player_finder(&data);
	printf("player is at (%d, %d)\n", data->player[0], data->player[1]);
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
		return (ft_free_map(data->parse), destroy_win(data), exit(0), 0);
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
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	init_textures(data);
	data->win = mlx_new_window(data->mlx, WINWIDTH, WINHEIGHT, "cub3d");
	if (data->win == NULL)
		return (1);
	data->img.mlx_img = mlx_new_image(data->mlx, WINWIDTH, WINHEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	printf("img->bpp = %d\n", data->img.bpp);
	mlx_loop_hook(data->mlx, &handle_no_event, data);
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

void	map_init(t_parse *parse)
{
	t_mlx	data;

	init_testmap(&data, parse);
	game_launcher(&data);
	return ;
}
