/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fetch_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/02/23 16:02:15 by theophane        ###   ########.fr       */
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
	data->lvl->map = malloc(sizeof(char *) * (parse->len_map + 1));
	if (data->lvl->map == NULL)
		return (1);
	data->lvl->map[parse->len_map] = '\0';
	while (parse->map[i])
	{
		data->lvl->map[i] = ft_strdup(parse->map[i]);
		i++;
	}
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
	data->lvl->lenX = parse->max_len;
	data->lvl->lenY = parse->len_map;
	return (0);
}