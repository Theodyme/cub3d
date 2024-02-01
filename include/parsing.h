/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:13:01 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/01 21:33:37 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef struct s_parse
{
	char	**textures;
	int		len_textures;
	char	**map;
	int		len_map;
}			t_parse;

int			name_checker(char *filename, int index);
void		ft_parse(char *path, t_parse *parse);
void		ft_open_file(char *path, t_parse *parse);
int			ft_make_textures_tab(char *path, t_parse *parse, int i);
void		ft_open_textures(t_parse *parse);
void		ft_free_map(t_parse *parse);
void		ft_open_rgb(t_parse *parse);
void		ft_change_texture(t_parse *parse, int i);

#endif