/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:12:25 by mderkaou          #+#    #+#             */
/*   Updated: 2024/01/31 20:23:41 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


void	ft_parse(char *path, t_parse *parse)
{
	printf("Parsing %s\n", path);
	if (name_checker(path, 0) == 1)
	{
		printf("Error\nWrong file extension\n");
		return ;
	}
	ft_open_file(path, parse);
}
void ft_open_file(char *path, t_parse *parse)
{
	int fd;
	char *line;
	int i;

	(void)parse;
	i = 0;
	fd = open(path, O_RDONLY | __O_DIRECTORY);
	if (fd == -1)
	{
		printf("Error\nCan't open file\n");
		return ;
	}
	while (i != 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			i = 1;
		else
		{
			printf("%s\n", line);
			free(line);
		}
	}
}
