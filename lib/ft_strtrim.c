/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:01:37 by flplace           #+#    #+#             */
/*   Updated: 2024/01/30 15:40:04 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strtrim(char *s1, char const *set)
{
	char			*str;
	char			*start;
	unsigned int	size;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr((char *)set, *s1))
		s1++;
	start = s1;
	size = ft_strlen((char *)s1);
	while (size && ft_strchr((char *)set, s1[size]))
		size--;
	str = ft_calloc((size + 1), sizeof(char));
	while (start[i])
	{
		if (ft_is_in_charset(start[i], (char *)set))
			i++;
		else
			str[j++] = start[i++];
	}
	return (str);
}

char	*ft_strtrim_free(char *s1, char const *set)
{
	char	*new_s;

	new_s = ft_strtrim(s1, set);
	free(s1);
	return (new_s);
}