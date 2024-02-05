/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:28:39 by diavolo           #+#    #+#             */
/*   Updated: 2024/02/05 20:01:22 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_verif_rgb(t_parse *parse, int i, int l)
{
	int		j;
	int		k;
	int		o;
	char	tmp[4];

	j = 1;
	k = 5;
	o = l;
	while (parse->textures[i][j] != '\0' && l < (o + 3))
	{
		if (parse->textures[i][j] >= '0' && parse->textures[i][j] <= '9')
		{
			tmp[j - 1] = parse->textures[i][j];
		}
		else if (parse->textures[i][j] == ',' && j < k)
		{
			tmp[j - 1] = '\0';
			parse->rgb[l] = ft_atoi(tmp);
			l++;
			k += 3;
		}
		else
			return (printf("Error\nRGB Error\n"), ft_free_map(parse), exit(0));
		j++;
	}
}

void	ft_open_rgb(t_parse *parse)
{
	if (parse->textures[4][0] == 'F' && parse->textures[4][1] >= '0'
		&& parse->textures[4][1] <= '9')
		ft_change_texture(parse, 4);
	else
		return (printf("Error\nF RGB Error\n"), ft_free_map(parse), exit(0));
	if (parse->textures[5][0] == 'C' && parse->textures[5][1] >= '0'
		&& parse->textures[5][1] <= '9')
		ft_change_texture(parse, 5);
	else
		return (printf("Error\nC RGB Error\n"), ft_free_map(parse), exit(0));
	parse->rgb = malloc(sizeof(int) * 6);
	ft_verif_rgb(parse, 4, 0);
}
