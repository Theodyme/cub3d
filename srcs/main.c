/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/03/15 11:18:32 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int ac, char **av)
{
	// int i = 0;	
	t_parse parse;
	t_mlx data;

	if (ac == 2)
	{
		parse.rgb = NULL;
		ft_parse(av[1], &parse);
		data_builder(&parse, &data);
		data.mlx = mlx_init();
		if (data.mlx == NULL)
			return (1);
		init_textures(&parse, &data);
		// ft_free_map(&parse);
		// if (parse.len_textures > 0)
		// {
		// 	i = -1;
		// 	while (++i < parse.len_textures)
		// 		free(parse.textures[i]);
		// 	free(parse.textures);
		// }
		// if (parse.rgb != NULL)
		// 	free(parse.rgb);
		game_launcher(&data);
		data_freer(&data);
	}
	else
		printf("Error\nWrong number of arguments\n");
	return (1);
}
