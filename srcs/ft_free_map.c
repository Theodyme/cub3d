/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:52:41 by diavolo           #+#    #+#             */
/*   Updated: 2024/02/27 15:23:52 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_map(t_parse *parse)
{
	int	i;

	i = -1;
	if (parse->len_map > 0)
	{
		while (++i < parse->len_map)
			free(parse->map[i]);
		free(parse->map);
	}
	if (parse->len_textures > 0)
	{
		i = -1;
		while (++i < parse->len_textures)
			free(parse->textures[i]);
		free(parse->textures);
	}
	if (parse->rgb != NULL)
		free(parse->rgb);
}

void	ft_free_map_cpy(t_parse *parse)
{
	int	i;

	i = -1;
	while (++i < parse->len_map)
	{
		if (parse->map_cpy != NULL)
			free(parse->map_cpy[i]);
	}
	if (parse->map_cpy != NULL)
		free(parse->map_cpy);
}
