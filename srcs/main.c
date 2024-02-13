/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:42:23 by flplace           #+#    #+#             */
/*   Updated: 2024/02/13 16:52:37 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_parse	parse;
	int		i;

	i = -1;
	if (ac == 2)
	{
		parse.rgb = NULL;
		ft_parse(av[1], &parse);
		printf("\n");
		while (++i < parse.len_textures)
		{
			printf("texture = %s\n", parse.textures[i]);
		}
		i = -1;
		ft_free_map(&parse);
		printf("\nbien fini\n");
	}
	else
		printf("Error\nWrong number of arguments\n");
	return (1);
}
