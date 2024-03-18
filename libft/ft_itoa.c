#include "libft.h"
#include <limits.h>

static int	get_size(int n, int base)
{
	int	len;
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int	len;
	char *result;

	len = get_size(n, 10);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = 0;
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n)
	{
		if (n > 0)
			result[--len] = (n % 10) + '0';
		else
			result[--len] = (n % 10 * -1) + '0';
		n /= 10;
	}
	return (result);
}
/*
int main()
{
    int num = INT_MIN;
    char *str = ft_itoa(num);

    if (str)
    {
        printf("int to ascii: %s\n", str);
        free(str);
    }
    else
    {
        printf("memory allocation failed\n");
    }

    return 0;
}
*/
