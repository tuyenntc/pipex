#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
void	modify_character(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		(*c)++;
}
/*
int	main()
{
	char str[] = "hello";
	printf("input: %s\n", str);
	ft_striteri(str, modify_character);
	printf("modified string: %s\n", str);
	return (0);
}
*/
