#include "libft.h"


void    *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *destination;
	unsigned char *source;
	
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (destination < source)
	{
		while (len--)
			*destination++ = *source++;
	}
	else if (!destination && !source)
		return (NULL);
	else
	{
		while (len--)
			destination[len] = source[len];
	}
	return (dst);
}
/*
void    *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dp = (unsigned char *)dst;
	const unsigned char *sp = (const unsigned char *)src;
	if (sp < dp && sp + len > dp)
	{
		sp += len;
		dp += len;
		while (len-- > 0)
		{
			*--dp = *--sp;
		}
	}
	else
	{
		while (len-- > 0)
		{
			*dp++ = *sp++;
		}
	}
	return (dst);
}

OR


void    *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		new_dst = (unsigned char *)dst;
		new_src = (unsigned char *)src;
		while (len--)
			*new_dst++ = *new_src++;
	}
	else
	{
		new_dst = dst + (len - 1);
		new_src = src + (len - 1);
		while (len--)
			*new_dst-- = *new_src--;
	}
	return (dst);
}
#include <string.h>

int	main(void)
{
	char	str1[] = "hello world";
	char	str2[20];
	strcpy(str2, "for testing");
	printf("before: str1 = %s, str2 = %s\n", str1, str2);
	ft_memmove(str2, str1, 13);
	printf("after: str1 = %s, str2 = %s\n", str1, str2);
	return (0);
}
*/
