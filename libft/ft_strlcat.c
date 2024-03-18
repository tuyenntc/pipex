#include "libft.h"
/*
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dstsize - 1 && dst[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && i < dstsize - 1)
	{
			dst[i] = src[j];
			i++;
			j++;
	}
	dst[i] = '\0';
	return (i + j);
}

int	main(void)
{
	char dest[50] = "42";
	char src[] = "is the answer";
	ft_strlcat(dest, src, sizeof(dest));
	printf("concat string is: %s\n", dest);
	return (0);
}
*/
// 2nd solution:
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	if (dst == NULL || src == NULL)
		return (0);
	char *d = dst;
	const char *s = src;
	size_t	n = dstsize;
	while (n-- != 0 && *d != '\0')
		d++;
	size_t dlen = d - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0' && n-- > 1)
			*d++ = *s++;
	*d = '\0';
	return (dlen + ft_strlen(src));
}
/* condense version of the above code
#include <stddef.h>

size_t ft_strlcat(char *dst, const char *src, size_t dstsize) {
    if (!dst || !src) return 0;

    size_t dlen = 0;
    while (dst[dlen] && dlen < dstsize) dlen++;

    size_t n = dstsize - dlen;
    if (n == 0) return dlen + ft_strlen(src);

    while (*src && n-- > 1) dst[dlen++] = *src++;
    dst[dlen] = '\0';

    while (*src++) dlen++;

    return dlen;
}
*/
