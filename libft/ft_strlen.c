#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

//compare with 0: [i] != '\0' is the same as s[i]: if s[i] is true....

//2nd solution
/*
 size_t  ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

OR
 size_t  ft_strlen(const char *s)
 {
	size_t	i = 0;
	while (*s++) 
		i++;
	return (i);

//3rd solution:
 size_t  ft_strlen(const char *s)
{
	const char *str;
	str = s;
	while (*s)
		++s;
	return (s - str);
}
start:
		hello\0
s-------^   
str_____^
end:	hello\0
s-------------^
str-----^
*/
/*
size_t	ft_strlen(const char *s)
{
	const char	*start;
	
	start = s;
	while (*s) s++;
	return (size_t)(s - start);
}
*/
/*
int	main(void)
{
	char	test[] = "hello";
	size_t	result;

	result = ft_strlen(test);
	printf("length %zu\n", result);
	return (0);
}

//4th solution:
size_t	ft_strlen(const char *s)
{
	const char	*eos;

	eos = s;
	while (*eos++);
	return ((int)(eos - s - 1));
}
*/
