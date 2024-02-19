/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/02/19 16:15:07 by theophane        ###   ########.fr       */
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
		ft_free_map(&parse);
		printf("\nbien fini\n");
	}
	else
		printf("Error\nWrong number of arguments\n");
	map_init();
	return (1);
}
