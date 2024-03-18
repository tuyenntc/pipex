#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	c;
	int	myfunc;
	int	libfunc;

	c = 65;
	myfunc = ft_isprint(c);
	libfunc = isprint(c);
	printf("myfunc: %d\n", myfunc);
	printf("libfunc: %d\n", libfunc);
	return (0);
}
*/
