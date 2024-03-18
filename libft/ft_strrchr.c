#include "libft.h"
char	*ft_strrchr(const char *s, int c)
{
	char *last;

	last = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
			last = (char *)s;
		++s;
	}
	if (c == 0)
		return ((char *)s);
	return (last);
}
/*
int	main(void)
{
	char	*input = "hello world";
	char	target = 'l';

	const char	*result = ft_strrchr(input, (int)target);
	if (result != NULL)
		printf("last character '%c' found at: %ld\n", target, result - input);
	else
		printf("character '%c' not found in the string\n", target);
	return (0);
}
*/
