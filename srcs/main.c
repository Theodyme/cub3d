/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:42:23 by flplace           #+#    #+#             */
/*   Updated: 2024/02/01 20:42:54 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		main(int ac, char **av)
{
	t_parse parse;
	int i = -1;
	if (ac == 2)
	{
		ft_parse(av[1], &parse);
		printf("\n");
		while (++i < parse.len_textures)
		{
			printf("texture = %s\n", parse.textures[i]);
		}
		i = -1;
		while (++i < parse.len_textures)
		{
			free(parse.textures[i]);
		}
		free(parse.textures);
	}
	else
		printf("Error\nWrong number of arguments\n");
	return (1);
}
