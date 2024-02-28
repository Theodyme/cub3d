/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/02/28 16:42:36 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_parse	parse;
	t_mlx	data;

	if (ac == 2)
	{
		parse.rgb = NULL;
		ft_parse(av[1], &parse);
		printf("\nbien fini\n");
		data_builder(&parse, &data);
		data.mlx = mlx_init();
		if (data.mlx == NULL)
			return (1);
		init_textures(&parse, &data);
		// ft_free_map(&parse);
		game_launcher(&data);
		data_freer(&data);
	}
	else
		printf("Error\nWrong number of arguments\n");
	return (1);
}
