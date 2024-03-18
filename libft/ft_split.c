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
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_free(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

size_t	ft_wordcount(char const *s, char c)
{
	size_t	list_size;
	size_t	i;

	list_size = i = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			list_size++;
		i++;
	}
	return (list_size);
}

char	**ft_split(char const *s, char c)
{
	char **str_list;
	size_t	i;
	size_t	k;
	size_t	save;

	i = k = 0;
	str_list = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!str_list)
		return (NULL);
	while (i < ft_wordcount(s, c) && s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		save = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		str_list[i] = ft_strndup(&s[save], k - save);
		if (str_list[i] == NULL)
			return (ft_free(str_list));
		i++;
	}
	str_list[i] = NULL;
	return (str_list);
}
/*
int	main()
{
	int	i;

	i = 0;
	const char *input = "this is the way";
	char **result = ft_split(input, ' ');
	if (result)
	{
		while (result[i] != NULL)
		{
			printf("array %d: %s\n", i + 1, result[i]);
			i++;
		}
		ft_free(result);
	}
	else
		printf("memory allocation failed\n");
	return (0);
}
*/
