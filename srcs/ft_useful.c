/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:27:34 by diavolo           #+#    #+#             */
/*   Updated: 2024/02/09 22:53:45 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_len_map(t_parse *parse)
{
	int	i;
	int	j;

	i = 6;
	j = 0;
	while (parse->textures[i] != NULL)
	{
		i++;
		j++;
	}
	parse->map = malloc(sizeof(char *) * (j + 1));
	parse->map[j] = NULL;
	parse->len_map = j;
	i = 6;
	j = 0;
	while (parse->textures[i] != NULL)
	{
		parse->map[j] = ft_strdup(parse->textures[i]);
		i++;
		j++;
	}
}
