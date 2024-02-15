/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:25 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/15 16:19:14 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_parse(char *path, t_parse *parse)
{
	init_parse(parse);
	if (name_checker(path, 0) == 1)
	{
		return (printf("Error\nWrong file extension\n"), (void)0);
	}
	ft_open_file(path, parse);
	ft_open_rgb(parse);
	ft_len_map(parse);
	ft_verif_map(parse);
	ft_parsing(parse, parse->len_map);
}

void	ft_open_file(char *path, t_parse *parse)
{
	int		fd;
	char	*line;
	int		i;

	i = ft_make_textures_tab(path, parse, 0);
	if (i == -1)
		return (printf("Error\nOpen\n"), ft_free_map(parse), exit(0));
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (i < 6)
			line = ft_strtrim_free(line, WHITESPACES);
		if (line != NULL)
		{
			parse->textures[i] = ft_strdup(line);
			i++;
			free(line);
		}
	}
	parse->textures[i] = NULL;
	close(fd);
	ft_open_textures(parse);
}
