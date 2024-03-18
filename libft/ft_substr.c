#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if(!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
/*

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	max_len;
	char	*substring;

	max_len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (NULL);
	if (max_len < len)
	{
		len = max_len;
	}
//	substring = (char *)malloc(len + 1);
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (substring == NULL)
		return (NULL);
	ft_strlcpy(substring, s + start, len);
	substring[len] = '\0';
	return (substring);
}

int	main()
{
	const char *original = "test string";
	unsigned int start = 5;
	size_t length = 8;
	char *result = ft_substr(original, start, length);
	if (result != NULL)
	{
		printf("substring: %s\n", result);
		free(result);
	}
	else
	{
		printf("allocation failed\n");
	}
	return (0);
}
*/
