#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char *str;
	size_t	i;
	i = 0;
	if (n == 0)
		return (NULL);
	str = (char *)malloc(n + 1);
	if (!str)
		return (NULL);
	while (i < n && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char **ft_free(char **list)
{
	size_t i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
	return (NULL);
}

size_t ft_wordcount(const char *s, char c)
{
	size_t	list_size = 0;
	while (*s)
	{
		if (*s != c)
		{
			list_size++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (list_size);
}

char **ft_split(const char *s, char c)
{
	char **str_list = (char **)malloc(sizeof(char *) * (ft_wordcount(s,c) + 1));
	if (!str_list)
		return (NULL);
	size_t i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			size_t	save = 0;
			while (s[save] &&s[save] != c)
				save++;
			str_list[i++] = ft_strndup(s, save);
			if (!str_list[i - 1])
				return (ft_free(str_list));
			s += save;
		}
	}
	str_list[i] = NULL;
	return (str_list);
}
/*
int	main(void)
{
	const char 	*input = "this is the way";
	char	**result = ft_split(input, ' ');
	if (result)
	{
		for (int i = 0; result[i] != NULL; ++i)
			printf("array %d: %s\n", i + 1, result[i]);
		ft_free(result);
	}
	else
		printf("memory allocation failed\n");
	return (0);
}
*/
