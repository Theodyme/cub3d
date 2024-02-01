/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diavolo <diavolo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:31:53 by flplace           #+#    #+#             */
/*   Updated: 2024/02/01 15:02:04 by diavolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	*tab;

	tab = (void *)malloc((size * count) + 1);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, (size * count) + 1);
	return (tab);
}
