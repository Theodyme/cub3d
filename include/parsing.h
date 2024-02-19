/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/02/19 16:13:27 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

typedef struct s_parse
{
	char	**textures;
	int		len_textures;
	int		*rgb;
	char	**map;
	int		len_map;
	int		count;
	int		n;
	int		s;
	int		e;
	int		w;
	int		f;
	int		c;
	int		v;
}			t_parse;

int			name_checker(char *filename, int index);
void		ft_parse(char *path, t_parse *parse);
void		ft_open_file(char *path, t_parse *parse);
int			ft_make_textures_tab(char *path, t_parse *parse, int i);
void		ft_open_textures(t_parse *parse);
void		ft_free_map(t_parse *parse);
void		ft_open_rgb(t_parse *parse);
void		ft_change_texture(t_parse *parse, int i, int o);
void		ft_len_map(t_parse *parse);
int			ft_parsing(t_parse *parse, int tablen);
void		ft_verif_map(t_parse *parse);
int			ft_check_wall(t_parse *parse, int i, int o);
void		init_parse(t_parse *parse);
void		ft_verif_nswe_two(t_parse *parse, int i);

#endif
