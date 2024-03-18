/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:36:26 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/18 13:13:04 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_verif_map(t_parse *parse)
{
	int	i;
	int	o;
	int	count;

	i = -1;
	count = 0;
	while (parse->map[++i])
	{
		o = -1;
		while (parse->map[i][++o] != '\0')
		{
			if (parse->map[i][o] == 'N' || parse->map[i][o] == 'S'
				|| parse->map[i][o] == 'E' || parse->map[i][o] == 'W')
				count++;
		}
	}
	if (count != 1)
		return (printf(RE "Error\nPlayer\n" RESET), ft_free_map(parse), exit(0));
}

int	ft_check_wall(t_parse *parse, int i, int o)
{
	if (i < 0 || o < 0 || i >= parse->len_map
		|| o >= (int)ft_strlen(parse->map[i]))
		return (1);
	if (o == 0 && parse->map[i][o] != '1')
		return (1);
	if (i == 0 && parse->map[i][o] != '1')
		return (1);
	if (ft_is_in_charset(parse->map[i][o + 1], "10") == 0)
		return (1);
	if (ft_is_in_charset(parse->map[i][o - 1], "10") == 0)
		return (1);
	if (ft_is_in_charset(parse->map[i + 1][o], "10") == 0)
		return (1);
	if (ft_is_in_charset(parse->map[i - 1][o], "10") == 0)
		return (1);
	return (0);
}
