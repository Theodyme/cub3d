/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:25 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/18 14:09:18 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	count_max_len(t_parse *parse)
{
	int	i;
	int	j;
	int	max_len;

	i = -1;
	max_len = 0;
	while (parse->map[++i] != NULL)
	{
		j = -1;
		while (parse->map[i][++j] != '\0')
		{
			if (j > max_len)
				max_len = j;
		}
	}
	parse->max_len = max_len;
	if (parse->max_len < 0)
		return (printf(RE "Error\nMap too small\n" RESET), ft_free_map(parse),
			exit(0));
}

void	ft_open_file(char *path, t_parse *parse)
{
	int		fd;
	char	*line;
	int		i;

	i = ft_make_textures_tab(path, parse, 0);
	if (i == -1)
		return (printf(RE "Error\nOpen\n" RESET), ft_free_map(parse), exit(0));
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

void	ft_is_directory(char *path)
{
	int	fd;

	fd = open(path, __O_DIRECTORY);
	if (fd != -1)
		return (printf(RE "Error\nIs a directory\n" RESET), close(fd), exit(0));
}

void	ft_parse(char *path, t_parse *parse)
{
	init_parse(parse);
	if (name_checker(path, 0) == 1)
	{
		return (printf(RE "Error\nWrong file extension\n" RESET), exit(0));
	}
	ft_is_directory(path);
	ft_open_file(path, parse);
	ft_open_rgb(parse);
	ft_len_map(parse);
	ft_verif_map(parse);
	ft_parsing(parse, parse->len_map);
	count_max_len(parse);
}
