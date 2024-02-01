/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:28:39 by diavolo           #+#    #+#             */
/*   Updated: 2024/02/01 21:39:32 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_open_rgb(t_parse *parse)
{
	if (parse->textures[4][0] == 'F' && parse->textures[4][1] >= '0' && parse->textures[4][1] <= '9')
		ft_change_texture(parse, 4);
	else
		return (printf("Error\nWrong file format\n"), ft_free_map(parse),
			exit(0));
	if (parse->textures[5][0] == 'C' && parse->textures[5][1] >= '0' && parse->textures[5][1] <= '9')
		ft_change_texture(parse, 5);
	else
		return (printf("Error\nWrong file format\n"), ft_free_map(parse),
			exit(0));
}
