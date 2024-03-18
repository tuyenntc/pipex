#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
//1st solution
/*
{
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
*/
//2nd solution
{
	int i = 0;
	while (n != '\0' && s1[i] && (s1[i] == s2[i]))
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)&s1[i] - *(unsigned char *)&s2[i]);
}
/*
int	main(void)
{
	char	*s1 = "abc";
	char	*s2 = "acb";
	int	result = ft_strncmp(s1, s2, 5);
	if (result == 0)
		printf("s1 = s2\n");
	else if (result > 0)
		printf("s1 > s2\n");
	else
		printf("s1 < s2\n");
	return (0);
}
*/
