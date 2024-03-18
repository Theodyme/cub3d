/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:19:14 by mderkaou          #+#    #+#             */
/*   Updated: 2024/03/18 13:36:11 by flplace          ###   ########.fr       */
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
		return (printf(RE "Error\nCan't open file\n" RESET), -1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line != NULL)
		{
			i++;
			free(line);
		}
	}
	close(fd);
	parse->textures = malloc(sizeof(char *) * (i + 1));
	if (parse->textures == NULL)
		return (printf(RE "Error\nMalloc error\n" RESET), -1);
	parse->textures[i] = NULL;
	parse->len_textures = i;
	return (0);
}

void	ft_change_texture(t_parse *parse, int i, int o)
{
	char	*tmp;
	int		j;

	if (parse->n > 1 || parse->s > 1 || parse->e > 1 || parse->w > 1
		|| parse->f > 1 || parse->c > 1)
		return (printf(RE "Error\nWrong number of map parameters\n" RESET), ft_free_map(parse), exit(0));
	if (o == 0 && parse->textures[i][0] != 'F' && parse->textures[i][0] != 'C')
		j = 2;
	else
		j = 1;
	tmp = ft_strdup(parse->textures[i] + j);
	if (tmp == NULL)
		return (printf(RE "Error\nMalloc error\n" RESET), ft_free_map(parse));
	free(parse->textures[i]);
	parse->textures[i] = tmp;
}

void	ft_verif_nswe(t_parse *parse)
{
	int	i;

	i = -1;
	parse->count = 0;
	while (++i < 6)
	{
		if (parse->textures[i][0] == 'N' && parse->textures[i][1] == 'O')
		{
			parse->n++;
			parse->n_id = i;
			ft_change_texture(parse, i, 0);
		}
		else if (parse->textures[i][0] == 'N')
		{
			parse->n++;
			parse->n_id = i;
			ft_change_texture(parse, i, 1);
		}
		else
			ft_verif_nswe_two(parse, i);
	}
}

void	ft_open_textures(t_parse *parse)
{
	int	i;
	int	fd;

	i = -1;
	ft_verif_nswe(parse);
	while (++i < 6)
	{
		if (i == parse->n_id || i == parse->s_id || i == parse->e_id
			|| i == parse->w_id)
		{
			fd = open(parse->textures[i], O_RDONLY);
			if (fd == -1)
				return (printf(RE "Error\nCan't open textures\n" RESET),
					ft_free_map(parse), exit(0));
			close(fd);
		}
	}
}
