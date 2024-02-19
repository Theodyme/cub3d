/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/02/19 16:39:41 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	t_parse	parse;

	if (ac == 2)
	{
		parse.rgb = NULL;
		ft_parse(av[1], &parse);
		printf("\n");
		printf("\nbien fini\n");
		map_init(&parse);
		ft_free_map(&parse);
	}
	else
		printf("Error\nWrong number of arguments\n");
	return (1);
}
