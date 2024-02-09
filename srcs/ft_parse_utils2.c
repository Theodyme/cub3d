/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:28:39 by diavolo           #+#    #+#             */
/*   Updated: 2024/02/09 23:07:02 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_verif_rgb(t_parse *parse, int i, int l, int index)
{
	char	tmp[4];
	int		j;

	j = 0;
	while (parse->textures[i][j] != '\0')
	{
		if (parse->textures[i][j] == ','
			|| j == (int)ft_strlen(parse->textures[i]) - 1)
		{
			if (j == (int)ft_strlen(parse->textures[i]) - 1)
				tmp[index++] = parse->textures[i][j];
			tmp[index] = '\0';
			if (ft_atoi(tmp) >= 0 && ft_atoi(tmp) <= 255)
				parse->rgb[l++] = ft_atoi(tmp);
			else
				return (printf("RGB Error\n"), ft_free_map(parse), exit(0));
			j++;
			index = 0;
		}
		else if (parse->textures[i][j] >= '0' && parse->textures[i][j] <= '9')
			tmp[index++] = parse->textures[i][j++];
		else
			return (printf("RGB numbers Error\n"), ft_free_map(parse), exit(0));
	}
}

void	ft_count_virgule(t_parse *parse, int i)
{
	int	j;
	int	count;

	while (i < 6)
	{
		j = 0;
		count = 0;
		while (parse->textures[i][j] != '\0')
		{
			if (parse->textures[i][j] == ',')
				count++;
			j++;
		}
		if (count != 2)
			return (printf("RGB ',' Error\n"), ft_free_map(parse), exit(0));
		i++;
	}
}

void	ft_open_rgb(t_parse *parse)
{
	if (parse->textures[4][0] == 'F' && parse->textures[4][1] >= '0'
		&& parse->textures[4][1] <= '9')
		ft_change_texture(parse, 4);
	else
		return (printf("F RGB Error\n"), ft_free_map(parse), exit(0));
	if (parse->textures[5][0] == 'C' && parse->textures[5][1] >= '0'
		&& parse->textures[5][1] <= '9')
		ft_change_texture(parse, 5);
	else
		return (printf("C RGB Error\n"), ft_free_map(parse), exit(0));
	parse->rgb = malloc(sizeof(int) * 6);
	if (parse->rgb == NULL)
		return (printf("Malloc error\n"), ft_free_map(parse), exit(0));
	ft_count_virgule(parse, 4);
	ft_verif_rgb(parse, 4, 0, 0);
	ft_verif_rgb(parse, 5, 3, 0);
	printf("F RGB = %d %d %d\n", parse->rgb[0], parse->rgb[1], parse->rgb[2]);
	printf("C RGB = %d %d %d\n", parse->rgb[3], parse->rgb[4], parse->rgb[5]);
}
