#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s)[index] == (unsigned char) c)
			return (((unsigned char *)s) + index);
		index++;
	}
	return (NULL);
}
/*
2nd solution
void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *str = (const char *)s;
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	char	s[] = "answer";
	char	*ptr = ft_memchr(s, 'e', sizeof(s));
	if (ptr != NULL)
	{
		printf("'e' is at position %ld\n", ptr-s+1);
		printf("search character found: %s\n", ptr);
	}
	else
	{
		printf("searched character not found\n");
	}
	return (0);
}
*/
