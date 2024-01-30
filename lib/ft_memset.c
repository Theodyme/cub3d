#include "../include/cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	if (!b)
		return (NULL);
	str = b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}
