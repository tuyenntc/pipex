#include "libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;//counter for iterating the source string
	
	if (!dstsize)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	dest[12];
	const char	*source = "hello world";
	size_t	size = sizeof(dest) / sizeof(dest[0]);
	size_t	copied = ft_strlcpy(dest, source, size);
	printf("copied %lu bytes: \"%s\"\n", (unsigned long)copied, dest);
	return (0);
}
*/
