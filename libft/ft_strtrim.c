#include "libft.h"

static int ft_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if(!s1 || !set)
		return (NULL);
	const char *start;
	const char *end;
	size_t	trimmed_len;
	char *trimmed;

	start = s1;
	end = s1 + ft_strlen(s1) - 1;

	while (*start && ft_in_set(*start, set))
		start++;
	while (end > start && ft_in_set(*end, set))
		end--;
	trimmed_len = (size_t)(end - start) + 1;
	trimmed = (char *)malloc(trimmed_len + 1);
	if (!(trimmed))
		return (NULL);
	ft_strlcpy(trimmed, start, trimmed_len + 1);
	trimmed[trimmed_len] = '\0';
	return (trimmed);
}
/*
char    *ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	size_t	trimmed_len;
	char	*trimmed;

	len = ft_strlen(s1);
	start = 0;
	end = len - 1;
	trimmed_len = end - start + 1;
	if (!s1 || !set)
		return (NULL);
	while (start < len && ft_strchr(set, s1[start]))
		start++;
	if (start == len)
		return (ft_strdup(""));
	while (end > start && ft_strchr(set, s1[len]))
		end--;
	trimmed = (char *)malloc(trimmed_len + 1);
	if (!trimmed)
		return (NULL);
	strlcpy(trimmed, s1 + start, trimmed_len);
	trimmed[trimmed_len] = '\0';
	return (trimmed);
}

int	main()
{
	const char *input = "   hello there    ";
	const char *set = " ";
	char *result = ft_strtrim(input, set);
	if (result != NULL)
	{
		printf("input string: \"%s\"\n", input);
		printf("trimmed string: \"%s\"\n", result);
		free(result);
	}
	else
		printf("memory allocation failed\n");
	return (0);
}
*/
