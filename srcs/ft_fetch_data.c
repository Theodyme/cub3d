/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/03/08 17:12:43 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* ------------------------------- map_cpy() ---------------------------------- */
/*
**		copie la map depuis parse.
*/

int map_cpy(t_parse *parse, t_mlx *data)
{
	int i;

	i = 0;
   	data->lvl = malloc(sizeof(t_map));
	if (data->lvl == NULL)
		return (printf(RE "Error: Couldn't allocate map.\n" RESET), 1);
	data->lvl->lenX = parse->max_len;
	data->lvl->lenY = parse->len_map;
	data->lvl->map = malloc(sizeof(char *) * (parse->len_map + 1));
	if (data->lvl->map == NULL)
		return (1);
	data->lvl->map[parse->len_map] = NULL;
	while (parse->map[i])
	{
		data->lvl->map[i] = ft_strdup(ft_strtrim_free(parse->map[i], "\n"));
		i++;
	}
	// data->lvl->map[i][0] = '\0';
	return (0);
}

/* ------------------------------- fetch_map_data() ---------------------------------- */
/*
**		récupère les datas de la map depuis parse.
*/

int	fetch_map_data(t_mlx *data, t_parse *parse)
{
	if (map_cpy(parse, data) == 1)
		return (printf(RE "Error: Couldn't allocate map.\n" RESET), 1);
	// map_printer(data->lvl->map, data->lvl->lenY);
	return (0);
}

/* ------------------------------- rgb_to_int() ---------------------------------- */
/*
**		convertit une valeur rgb en int grâce à des décalages binaires.
*/

int		rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

/* ------------------------------- init_textures() ---------------------------------- */
/*
**		récupère les textures et les stockes dans data.
*/

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
	data->assets->nwall->mlx_img = mlx_xpm_file_to_image(data->mlx,
												parse->textures[parse->n_id],
												&width,
												&height);
	data->assets->nwall->addr = (int *)mlx_get_data_addr(data->assets->nwall->mlx_img, &data->assets->nwall->bpp, &data->assets->nwall->line_len, &data->assets->nwall->endian);
	data->assets->swall->mlx_img = mlx_xpm_file_to_image(data->mlx,
												parse->textures[parse->s_id],
												&width,
												&height);
	data->assets->wwall->mlx_img = mlx_xpm_file_to_image(data->mlx,
												parse->textures[parse->w_id],
												&width,
												&height);
	data->assets->ewall->mlx_img = mlx_xpm_file_to_image(data->mlx,
												parse->textures[parse->e_id],
												&width,
												&height);
	data->assets->floor = rgb_to_int(parse->rgb[0], parse->rgb[1],
			parse->rgb[2]);
	data->assets->ceiling = rgb_to_int(parse->rgb[3], parse->rgb[4],
			parse->rgb[5]);
}
