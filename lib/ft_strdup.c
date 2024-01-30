#include "../include/cub3d.h"

char	*ft_strdup(const char *src)
{
	int		l;
	char	*str;

	if (src == NULL)
		return (NULL);
	l = ft_strlen((char *)src);
	str = (char *)ft_calloc(sizeof(*str), (l + 1));
	if (str == NULL)
		return (NULL);
	str = ft_strcpy(str, src);
	return (str);
}
