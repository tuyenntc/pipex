int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	c;
	int	myfunc;
	int	libfunc;

	c = 'f';
	myfunc = ft_toupper(c);
	libfunc = toupper(c);
	printf("myfunc: %c\n", myfunc);
	printf("libfunc: %c\n", libfunc);
	return (0);
}
*/
