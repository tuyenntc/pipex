#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	b = '\0';
	unsigned char *mem = (unsigned char *)s;

	while (n--)
	{
		*mem++ = b;
	}
}
/*
#include <string.h>

int	main(void)
{
	char s[5] = "bzero";
	memset(s, 0, 4);
	ft_bzero(s, 4);
	printf("modified string: %s\n", s);
	return (0);
}
*/
