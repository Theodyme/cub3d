/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:25:45 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/15 16:24:16 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_p_posi(char **tab)
{
	int	i;
	int	o;

	i = 0;
	while (tab[i])
	{
		o = 0;
		while (tab[i][o])
		{
			if (tab[i][o] == 'N' || tab[i][o] == 'S' || tab[i][o] == 'E'
				|| tab[i][o] == 'W')
				return (i);
			o++;
		}
		i++;
	}
	return (-1);
}

int	ft_p_poso(char **tab)
{
	int	i;
	int	o;

	i = -1;
	while (tab[++i])
	{
		o = -1;
		while (tab[i][++o])
		{
			if (tab[i][o] == 'N' || tab[i][o] == 'S' || tab[i][o] == 'E'
				|| tab[i][o] == 'W')
				return (o);
		}
	}
	return (-1);
}

int	ft_last_verif(t_parse *parse)
{
	int	i;
	int	o;

	i = -1;
	while (parse->map[++i])
	{
		o = -1;
		while (parse->map[i][++o])
		{
			if (ft_is_in_charset(parse->map[i][o], "01\t \n") == 0)
				return (1);
		}
	}
	return (0);
}

void	ft_paint(t_parse *parse, int i, int o, int tablen)
{
	if (i < 0 || o < 0 || i >= tablen || o >= (int)ft_strlen(parse->map[i]))
		return ;
	if (ft_is_in_charset(parse->map[i][o], "0NSWE") == 0)
		return ;
	if (parse->map[i][o] != 1 && ft_check_wall(parse, i, o) == 1)
	{
		parse->v = 1;
		return ;
	}
	parse->map[i][o] = '1';
	ft_paint(parse, i + 1, o, tablen);
	ft_paint(parse, i - 1, o, tablen);
	ft_paint(parse, i, o + 1, tablen);
	ft_paint(parse, i, o - 1, tablen);
}

int	ft_parsing(t_parse *parse, int tablen)
{
	int	i;
	int	o;

	i = ft_p_posi(parse->map);
	o = ft_p_poso(parse->map);
	ft_paint(parse, i, o, tablen);
	if (parse->v == 1)
		return (printf("Error\nMap\n"), ft_free_map(parse), exit(0), 1);
	if (ft_last_verif(parse) == 1)
		return (printf("Error\nMap\n"), ft_free_map(parse), exit(0), 1);
	return (0);
}
