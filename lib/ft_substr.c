/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:01:40 by flplace           #+#    #+#             */
/*   Updated: 2024/01/30 15:04:57 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	char	*ref;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ref = new;
	if (ft_strlen((char *)s) > start)
		while (len-- > 0)
			*new++ = *(s + (start++));
	*new = '\0';
	return (ref);
}
