#include "libft.h"

/*
void    *ft_memset(void *b, int c, size_t len)
{
	unsigned char *p = b;
	while (len--)
	{
		*p++ = (unsigned char) c;
	}
	return (b);
}

void	printArray(char arr[], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%c\n", arr[i]);
		i++;
	}
}

int	main(void)
{
	char	arr[SIZE_ARRAY] = "ABCD";
	printArray(arr,SIZE_ARRAY);
	ft_memset(arr, '*', sizeof(arr));
	printArray(arr,SIZE_ARRAY);
	memset(arr, '@', 2);
	printArray(arr,SIZE_ARRAY);
	return (0);
}
*/
//another solution
/*
void *ft_memset(void *dest,  int c, size_t len)
{
    unsigned char *mem = dest;

    if(mem)
        while (len--)
            *mem++ = c;
    return dest;
}
*/


//2nd solution
void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	unsigned char	s;
	unsigned char	*mem;

	mem = b;
	s = c;
	i = 0;
	while (i < len)
	{
		mem[i] = s;
		i++;
	}
	return (b);
}
/*
int	main(void)
{
	char str[50] = "hello cowboy bebop pike";
	printf("\nBefore memset():%s\n", str);
	ft_memset(str + 13, '*',8*sizeof(char));
	printf("After memset(): %s\n", str);
	memset(str, '#', 5);
	printf("call memset function from lib: %s\n", str);
	return (0);
}
*/
