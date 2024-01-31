/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:42:23 by flplace           #+#    #+#             */
/*   Updated: 2024/01/30 17:21:59 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		main(int ac, char **av)
{
	t_parse parse;
	if (ac == 2)
	{
		ft_parse(av[1], &parse);
	}
	else
		printf("Error\nWrong number of arguments\n");
	return (1);
}
