#include "../include/cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	*tab;

	tab = (void *)malloc(size * count);
	if (!tab)
		return (NULL);
	ft_memset(tab, 0, size * count);
	return (tab);
}
