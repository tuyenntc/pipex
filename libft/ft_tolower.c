#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char	c;
	int	myfunc;
	int	libfunc;

	c = 'F';
	myfunc = ft_tolower(c);
	libfunc = tolower(c);
	printf("myfunc: %c\n", myfunc);
	printf("libfunc: %c\n", libfunc);
	return (0);
}
*/
