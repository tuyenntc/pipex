#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char *str;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f((unsigned int)i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}
/*
char f(unsigned int i, char c)
{
	char str;
	str = c + 1;
	return (str);
}
int	main()
{
	char	str1[] = "abc";
	char *str2 = ft_strmapi(str1, f);
	if (str2)
	{
		printf("%s\n", str2);
		free(str2);
	}
	else
		printf("memory allocation failed\n");
	return (0);
}
*/
