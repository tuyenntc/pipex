#include "libft.h"
//1st solution:
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
			return (0);
	while ((*ptr1 == *ptr2) && n - 1 > 0)
	{
		ptr1++;
		ptr2++;
		n--;
	}
	return ((int)(*ptr1 - *ptr2));
}

//2nd solution:
/*
int ft_ memcmp(const void *s1, const void *s2, size_t n) {
    const unsigned char *p1 = s1, *p2 = s2;

    while (n-- > 0) {
        if (*p1 != *p2) {
            return (*p1 - *p2);
        }
        p1++;
        p2++;
    }

    return 0;  // Memory blocks are identical
}

int main(void)
{
    char str1[] = "hello";
    char str2[] = "hellp";

    int result = ft_memcmp(str1, str2, 5);

    if (result == 0)
        printf("The memory blocks are identical.\n");
    else if (result < 0)
        printf("The first differing byte is smaller in str1.\n");
    else
        printf("The first differing byte is smaller in str2.\n");

    return 0;
}
*/
