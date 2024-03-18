#include "libft.h"
/*
void    *ft_memcpy(void *dst, const void *src, size_t n)

{
	size_t	i;

	i = 0;
	//create 2 new pointer variables and casting void pointer to a char pointer, must do this as void pointer will not work
	char	*src_char = (char *)src;
	char	*dst_char = (char *)dst;
	if (dst == NULL)
		return NULL;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return (dst);
}
*/

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_char;
	const char	*src_char;

	if (!n)
		return(dst);
	if (!dst && !src)
		return (NULL);
	dst_char = dst;
	src_char = src;
	while (n--)
		*dst_char++ = *src_char++;
	return (dst);
}


/*
void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst != src)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

*/
/*
#include <string.h>
int	main(void)
{
	char	src[] = "hello world";
	char	dst[100];
	ft_memcpy(dst, src, strlen(src) + 1);
	printf("the copied string is %s\n", dst);
	return (0);
}
*/
