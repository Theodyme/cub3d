/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theophane <theophane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/02/19 16:13:14 by theophane        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "utils.h"

char	*ft_strtrim(char *s1, char const *set)
{
	char			*str;
	char			*start;
	unsigned int	size;
	int				i;
	int				j;

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
	if (j == 0)
		{
			free(str);
			return (NULL);
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
