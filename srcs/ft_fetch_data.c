/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:20:27 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/18 14:16:29 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ---------------- map_cpy() ------------------- */
/*
**		copie la map depuis parse.
*/

int	map_cpy(t_parse *parse, t_mlx *data)
{
	int	i;

	i = 0;
	data->lvl = malloc(sizeof(t_map));
	if (data->lvl == NULL)
		return (printf(RE "Error: Couldn't allocate map.\n" RESET), 1);
	data->lvl->lenx = parse->max_len;
	data->lvl->leny = parse->len_map;
	data->lvl->map = malloc(sizeof(char *) * (parse->len_map + 1));
	if (data->lvl->map == NULL)
		return (1);
	data->lvl->map[parse->len_map] = NULL;
	while (parse->map[i])
	{
		data->lvl->map[i] = ft_strtrim_free(parse->map[i], "\n");
		i++;
	}
	return (0);
}

/* --------------- fetch_map_data() ---------------------- */
/*
**		récupère les datas de la map depuis parse.
*/

int	fetch_map_data(t_mlx *data, t_parse *parse)
{
	if (map_cpy(parse, data) == 1)
		return (printf(RE "Error: Couldn't allocate map.\n" RESET), 1);
	free(parse->map);
	parse->map = NULL;
	return (0);
}

/* --------------------- rgb_to_int() ----------------------- */
/*
**		convertit une valeur rgb en int grâce à des décalages binaires.
*/

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

/* --------------------- init_textures() ------------------- */
/*
**		ouvre les images xpm to image mlx.
*/

int	fetch_xpm_image(void **mlx, t_img *asset, char **textures, int id)
{
	asset->mlx_img = mlx_xpm_file_to_image(*mlx, textures[id], &asset->width,
			&asset->height);
	asset->addr = (int *)mlx_get_data_addr(asset->mlx_img, &asset->bpp,
			&asset->line_len, &asset->endian);
	if (asset->height != asset->width)
		return (1);
	return (0);
}

/* ----------------------- init_textures() ------------------ */
/*
**		récupère les textures et les stockes dans data.
*/

void	init_textures(t_parse *parse, t_mlx *data)
{
	int	out;

	out = 0;
	data->assets = malloc(sizeof(t_assets));
	if (data->assets == NULL)
		return (printf(RE "Error\nMalloc\n" RESET), ft_free_map(parse), exit(0));
	assets_init(data->assets);
	out += fetch_xpm_image(&data->mlx, data->assets->nwall, parse->textures,
			parse->n_id);
	out += fetch_xpm_image(&data->mlx, data->assets->swall, parse->textures,
			parse->s_id);
	out += fetch_xpm_image(&data->mlx, data->assets->wwall, parse->textures,
			parse->w_id);
	out += fetch_xpm_image(&data->mlx, data->assets->ewall, parse->textures,
			parse->e_id);
	if (out)
	{
		printf(RE "Error\nWrong asset dimensions.\n" RESET);
		ft_free_map(parse);
		escape(data);
	}
	data->assets->floor = rgb_to_int(parse->rgb[0], parse->rgb[1],
			parse->rgb[2]);
	data->assets->ceiling = rgb_to_int(parse->rgb[3], parse->rgb[4],
			parse->rgb[5]);
}
