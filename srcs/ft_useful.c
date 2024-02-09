/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:27:34 by diavolo           #+#    #+#             */
/*   Updated: 2024/02/09 23:04:29 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_len_map(t_parse *parse)
{
	int	i;
	int	j;

	i = 5;
	j = 0;
	while (parse->textures[++i] != NULL)
		j++;
	parse->map = malloc(sizeof(char *) * (j + 1));
	if (parse->map == NULL)
		return (printf("Malloc error\n"), ft_free_map(parse), exit(0));
	parse->map[j] = NULL;
	parse->len_map = j;
	i = 5;
	j = 0;
	while (parse->textures[++i] != NULL)
	{
		parse->map[j] = ft_strdup(parse->textures[i]);
		j++;
	}
	i = 5;
	while (parse->textures[++i] != NULL)
		free(parse->textures[i]);
	parse->len_textures = 6;
}
