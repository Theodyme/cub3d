/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useful.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:27:34 by diavolo           #+#    #+#             */
/*   Updated: 2024/02/20 16:13:14 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_cut_loop(t_parse *parse, int i)
{
	int	o;

	while (parse->textures[++i] != NULL)
	{
		o = -1;
		while (parse->textures[i][++o])
		{
			if (parse->textures[i][o] != ' ' && parse->textures[i][o] != '\0'
				&& parse->textures[i][o] != '\n'
				&& parse->textures[i][o] != '\t'
				&& parse->textures[i][o] != '\v'
				&& parse->textures[i][o] != '\f'
				&& parse->textures[i][o] != '\r')
				return (i - 1);
		}
	}
	return (1);
}

void	ft_len_map(t_parse *parse)
{
	int	i;
	int	j;
	int	o;

	i = ft_cut_loop(parse, 5);
	o = i;
	j = 0;
	while (parse->textures[++i] != NULL)
		j++;
	parse->map = malloc(sizeof(char *) * (j + 1));
	if (parse->map == NULL)
		return (printf("Error\nMalloc\n"), ft_free_map(parse), exit(0));
	parse->map[j] = NULL;
	parse->len_map = j;
	i = o;
	j = -1;
	while (parse->textures[++i] != NULL)
		parse->map[++j] = ft_strdup(parse->textures[i]);
	parse->map[++j] = NULL;
	i = 5;
	while (parse->textures[++i] != NULL)
		free(parse->textures[i]);
	parse->len_textures = 6;
}

void	init_parse(t_parse *parse)
{
	parse->v = 0;
	parse->n = 0;
	parse->s = 0;
	parse->w = 0;
	parse->e = 0;
	parse->len_map = -1;
	parse->len_textures = -1;
	parse->f = 0;
	parse->c = 0;
	parse->map = NULL;
	parse->len_map = -1;
}

void	ft_cpy_map(t_parse *parse)
{
	int i;

	i = 0;
	parse->map_cpy = malloc(sizeof(char *) * (parse->len_map + 1));
	if (parse->map_cpy == NULL)
		return (printf("Error\nMalloc\n"), ft_free_map(parse), exit(0));
	parse->map_cpy[parse->len_map] = NULL;
	while (parse->map[i] != NULL)
	{
		parse->map_cpy[i] = ft_strdup(parse->map[i]);
		i++;
	}
}
