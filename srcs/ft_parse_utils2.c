/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:28:39 by diavolo           #+#    #+#             */
/*   Updated: 2024/03/18 14:07:41 by mderkaou         ###   ########.fr       */
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
				return (printf("Error\nRGB\n"), ft_free_map(parse), exit(0));
			j++;
			index = 0;
		}
		else if (parse->textures[i][j] >= '0' && parse->textures[i][j] <= '9')
			tmp[index++] = parse->textures[i][j++];
		else
			return (printf(RE "Error\nRGB numbers\n" RESET), ft_free_map(parse),
				exit(0));
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
		if (i == parse->rgb_f || i == parse->rgb_c)
		{
			while (parse->textures[i][j] != '\0')
			{
				if (parse->textures[i][j] == ',')
					count++;
				j++;
			}
			if (count != 2)
				return (printf(RE "Error\nRGB ','\n" RESET), ft_free_map(parse),
					exit(0));
		}
		i++;
	}
}

void	ft_open_rgb_two(t_parse *parse, int i)
{
	if (parse->textures[i][0] == 'F' && parse->textures[i][1] >= '0'
		&& parse->textures[i][1] <= '9')
	{
		parse->f++;
		parse->rgb_f = i;
		ft_change_texture(parse, i, 1);
	}
	else if (parse->textures[i][0] == 'C' && parse->textures[i][1] >= '0'
			&& parse->textures[i][1] <= '9')
	{
		parse->c++;
		parse->rgb_c = i;
		ft_change_texture(parse, i, 1);
	}
	else if (i == 5 && (parse->f > 1 || parse->c > 1))
		return (printf(RE "Error\nRGB\n" RESET), ft_free_map(parse), exit(0));
}

void	ft_rgb_int(t_parse *parse)
{
	int	i;

	i = -1;
	while (parse->textures[parse->rgb_f][++i])
	{
		if (ft_is_in_charset(parse->textures[parse->rgb_f][i],
			"0123456789,") == 0)
			return (printf(RE "Error\nwrong arguments for rgb\n" RESET),
				ft_free_map(parse), exit(0));
	}
	i = -1;
	while (parse->textures[parse->rgb_c][++i])
	{
		if (ft_is_in_charset(parse->textures[parse->rgb_c][i],
			"0123456789,") == 0)
			return (printf(RE "Error\nwrong arguments for rgb\n" RESET),
				ft_free_map(parse), exit(0));
	}
}

void	ft_open_rgb(t_parse *parse)
{
	int	i;

	i = -1;
	while (++i < 6)
		ft_open_rgb_two(parse, i);
	parse->rgb = malloc(sizeof(int) * 6);
	if (parse->rgb == NULL)
		return (printf(RE "Error\nMalloc\n" RESET), ft_free_map(parse), exit(0));
	ft_count_virgule(parse, 4);
	ft_rgb_int(parse);
	ft_verif_rgb(parse, parse->rgb_f, 0, 0);
	ft_verif_rgb(parse, parse->rgb_c, 3, 0);
}
