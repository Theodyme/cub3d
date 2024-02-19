/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:13:05 by theophane         #+#    #+#             */
/*   Updated: 2024/02/19 15:13:06 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strcmp(const char *s1, const char *s2);
void	*ft_calloc(size_t count, size_t size);
int		ft_is_in_charset(const char c, const char *charset);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
char	*ft_strtrim(char *s1, char const *set);
char	*ft_strtrim_free(char *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *nptr);

#endif
