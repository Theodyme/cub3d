/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flplace <flplace@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:04:00 by flplace           #+#    #+#             */
/*   Updated: 2024/01/30 16:32:16 by flplace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	if (s == NULL)
		return (NULL);
	while (s[++i] != (char)c)
		if (s[i] == '\0')
			return (NULL);
	return ((char *)&(s[i]));
}
