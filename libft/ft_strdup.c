#include "libft.h"

char    *ft_strdup(const char *s1)
{
	char	*new;
	int	i;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}
/*
int	main(int ac, char **av)
{
	char	*myfunc;
	char	*libfunc;
	if (ac == 2)
	{
		myfunc = ft_strdup(av[1]);
		libfunc = strdup(av[1]);
		printf(":%s:\n:%s:\n", myfunc, libfunc);
	}
	return (0);
}
*/
/*
char    *ft_strdup(const char *s1)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dest = malloc(len);
	if(dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, len);
	return (dest);
}

int	main()
{
	const char	*input = "hello world";
	char	*result = ft_strdup(input);
	if (result != NULL)
	{
		printf("Empty string: Result: %s\n", result);
		free(result);
	}
	else
		printf("memory allocation failed\n");
	return (0);
}
*/
