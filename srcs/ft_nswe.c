/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nswe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:31:56 by diavolo           #+#    #+#             */
/*   Updated: 2024/02/15 16:44:08 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_verif_nswe_three(t_parse *parse, int i)
{
	if (parse->textures[i][0] == 'E' && parse->textures[i][1] == 'A')
	{
		parse->e++;
		ft_change_texture(parse, i, 0);
	}
	else if (parse->textures[i][0] == 'E')
	{
		parse->e++;
		ft_change_texture(parse, i, 1);
	}
}

void	ft_verif_nswe_two(t_parse *parse, int i)
{
	if (parse->textures[i][0] == 'S' && parse->textures[i][1] == 'O')
	{
		parse->s++;
		ft_change_texture(parse, i, 0);
	}
	else if (parse->textures[i][0] == 'S')
	{
		parse->s++;
		ft_change_texture(parse, i, 1);
	}
	if (parse->textures[i][0] == 'W' && parse->textures[i][1] == 'E')
	{
		parse->w++;
		ft_change_texture(parse, i, 0);
	}
	else if (parse->textures[i][0] == 'W')
	{
		parse->w++;
		ft_change_texture(parse, i, 1);
	}
	ft_verif_nswe_three(parse, i);
}
