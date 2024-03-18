/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:05:15 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/18 13:13:10 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_te(t_parse *parse)
{
	int	i;

	i = -1;
	while (++i < parse->len_textures)
		free(parse->textures[i]);
	free(parse->textures);
}

int	main(int ac, char **av)
{
	t_parse	parse;
	t_mlx	data;

	if (ac == 2)
	{
		parse.rgb = NULL;
		ft_parse(av[1], &parse);
		data_builder(&parse, &data);
		data.mlx = mlx_init();
		data.win = NULL;
		if (data.mlx == NULL)
			return (1);
		init_textures(&parse, &data);
		if (parse.len_textures > 0)
			free_te(&parse);
		if (parse.rgb != NULL)
			free(parse.rgb);
		game_launcher(&data);
		data_freer(&data);
	}
	else
		printf(RE "Error\nWrong number of arguments\n" RESET);
	return (1);
}
