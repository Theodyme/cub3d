/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:42:23 by flplace           #+#    #+#             */
/*   Updated: 2024/01/30 15:43:29 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		main(int ac, char **av)
{
	(void)ac;
	char *cpy;

	cpy = ft_strtrim(av[1], WHITESPACES);
	printf("%s\n", cpy);
	free(cpy);
	return (1);
}

