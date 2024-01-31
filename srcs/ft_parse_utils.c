/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/01/31 20:26:06 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int    name_checker(char *filename, int index)
{
    int    i;

    i = ft_strlen(filename) - 4;
    if (i <= 4)
	{
    	return (1);
	}
	if (index == 0)
    	if (ft_strcmp((filename + i), ".cub") != 0)
        	return (1);
	if (index == 1)
		if (ft_strcmp((filename + i), ".xpm") != 0)
			return (1);
    return (0);
}

