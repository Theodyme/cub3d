/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderkaou <mderkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/02/13 16:03:27 by mderkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	name_checker(char *filename, int index)
{
	int	i;

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

int	ft_make_textures_tab(char *path, t_parse *parse, int i)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nCan't open file\n"), -1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		line = ft_strtrim_free(line, WHITESPACES);
		if (line != NULL)
		{
			i++;
			free(line);
		}
	}
	close(fd);
	parse->textures = malloc(sizeof(char *) * (i + 1));
	if (parse->textures == NULL)
		return (printf("Error\nMalloc error\n"), -1);
	parse->textures[i] = NULL;
	parse->len_textures = i;
	return (0);
}

void	ft_change_texture(t_parse *parse, int i, int o)
{
	char	*tmp;
	int		j;

	if (i < 4 && o == 0)
		j = 2;
	else
		j = 1;
	tmp = malloc(sizeof(char) * ((ft_strlen(parse->textures[i]) - j) + 1));
	if (tmp == NULL)
		return (printf("Error\nMalloc error\n"), ft_free_map(parse));
	tmp = ft_strcpy(tmp, parse->textures[i] + j);
	free(parse->textures[i]);
	parse->textures[i] = tmp;
}

void	ft_verif_nswe(t_parse *parse)
{
	if (parse->textures[0][0] == 'N' && parse->textures[0][1] == 'O')
		ft_change_texture(parse, 0, 0);
	else if (parse->textures[0][0] == 'N')
		ft_change_texture(parse, 0, 1);
	if (parse->textures[1][0] == 'S' && parse->textures[1][1] == 'O')
		ft_change_texture(parse, 1, 0);
	else if (parse->textures[1][0] == 'S')
		ft_change_texture(parse, 1, 1);
	if (parse->textures[2][0] == 'W' && parse->textures[2][1] == 'E')
		ft_change_texture(parse, 2, 0);
	else if (parse->textures[2][0] == 'W')
		ft_change_texture(parse, 2, 1);
	if (parse->textures[3][0] == 'E' && parse->textures[3][1] == 'A')
		ft_change_texture(parse, 3, 0);
	else if (parse->textures[3][0] == 'E')
		ft_change_texture(parse, 3, 1);
}

void	ft_open_textures(t_parse *parse)
{
	int	i;
	int	fd;

	i = -1;
	ft_verif_nswe(parse);
	while (++i < 4)
	{
		fd = open(parse->textures[i], O_RDONLY);
		if (fd == -1)
			return (printf("Error\nCan't open textures\n"), ft_free_map(parse),
					exit(0));
		close(fd);
	}
}
