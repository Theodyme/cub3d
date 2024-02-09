/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:25 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/09 22:54:10 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_parse(char *path, t_parse *parse)
{
	int	i;

	i = 0;
	printf("path = %s\n", path);
	parse->len_map = -1;
	parse->len_textures = -1;
	if (name_checker(path, 0) == 1)
	{
		printf("Error\nWrong file extension\n");
		return ;
	}
	ft_open_file(path, parse);
	ft_open_rgb(parse);
	ft_len_map(parse);
	while (parse->map[i] != NULL)
	{
		printf("map = %s\n", parse->map[i]);
		i++;
	}
}

void	ft_open_file(char *path, t_parse *parse)
{
	int		fd;
	char	*line;
	int		i;

	i = ft_make_textures_tab(path, parse, 0);
	if (i == -1)
		return (printf("Error\nCan't open file\n"), ft_free_map(parse),
			exit(0));
	fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line = ft_strtrim_free(line, WHITESPACES);
		if (line != NULL)
		{
			printf("gnl a donne %s\n", line);
			parse->textures[i] = ft_strdup(line);
			i++;
			free(line);
		}
	}
	close(fd);
	ft_open_textures(parse);
}
