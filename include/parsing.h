/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:13:01 by mderkaou          #+#    #+#             */
/*   Updated: 2024/01/31 20:08:15 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PARSING_H
# define PARSING_H

#include "cub3d.h"

typedef struct s_parse
{
	char	**textures;
	char	**map;
}				t_parse;


int   name_checker(char *filename, int index);
void	ft_parse(char *path, t_parse *parse);
void ft_open_file(char *path, t_parse *parse);


#endif