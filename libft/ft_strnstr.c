#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	if (*needle == '\0' || (!haystack && len == 0))
		return (char *)haystack;
	while (*haystack && len--)
	{
		j = 0;
		while (haystack[j] == needle[j] && needle[j] && j <= len)
		{
			if (!needle[j + 1])
				return (char *)haystack;
			j++;
		}
		haystack++;
	}
	return (NULL);
}
/*
char	*ft_strnstr(char const *haystack, char const *needle, size_t n)
{
	size_t	j;

	if (!haystack && !n)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && n--)
	{
		j = 0;
		while (*(haystack + j) == *(needle + j)
			&& *(needle + j) && j <= n)
		{
			if (!*(needle + j + 1))
				return ((char *)haystack);
			j++;
		}
		haystack++;
	}
	return (NULL);
}

int	main(void)
{	
	const char *haystack = "abcxyzghj";
	const char *needle = "klm";
	char	*result = ft_strnstr(haystack, needle, 9);
	if (result != NULL)
		printf("found substring>> %s at position %ld\n", needle, result - haystack);
	else
		printf("substring>> %s is not found in the string %s\n", needle, haystack);
	return (0);
}

int	main(void)
{
	const char	*haystack = "blue sky sometimes blink";
	const char	*needle1 = "blink";
	const char	*needle2 = "wuf";
	const char	*needle3 = "";

	char *result1 = ft_strnstr(haystack, needle1, 25);
	char *result2 = ft_strnstr(haystack, needle2, 25);
	char *result3 = ft_strnstr(haystack, needle3, 25);
	if (result1 != NULL)
		printf("found %s at position %ld\n", needle1, result1 - haystack);
	else
		printf("not found\n");
	if (result2 != NULL)
		printf("found %s at position %ld\n", needle2, result2 - haystack);
	else
		printf("not found\n");
	if (result3 != NULL)
		printf("found %s at position %ld\n", needle3, result3 - haystack);
	else
		printf("not found\n");
	return (0);
}
*/
