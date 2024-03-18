#include "libft.h"
/*
//1st solution

char *ft_strchr(const char *s, int c)
{
	while (1)
	{
		++s;
		if (*s == (char)c)
			return ((char *)s);
		if (*s == '\0')
			return (NULL);
	}
}


//2nd solution
*/
char *ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
		if (*s == (char)c)
			return (char *)s;
		return (NULL);
}

/*
int	main(void)
{
	char	text[] = "hello";
	char	ch_find = 'o';
	char	*result = ft_strchr(text, ch_find);
	if (result != NULL)
		printf("character found at position %ld\n", result - text);
	else
		printf("character not found\n");
	return (0);
}
*/
