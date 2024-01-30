/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:42:25 by flplace           #+#    #+#             */
/*   Updated: 2024/01/30 15:40:56 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "colors.h"
#include "../mlx/mlx.h"

# define WHITESPACES "\t\r\v\f\n "

// ****************************************************************************
// UTILS

void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char *s1, char const *set);
char	*ft_strtrim_free(char *s1, char const *set);
size_t	ft_strlen(const char *str);
int		ft_is_in_charset(const char c, const char *charset);


#endif
