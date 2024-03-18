#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
	if(size != 0 && count > SIZE_MAX / size)
		return (NULL);
	void *ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr,0, count * size);
	return (ptr);
}
/*
void    *ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	tmp = malloc(count * size);
	if (tmp == 0)
		return (0);
	ft_memset(s, 0, count * size);
	return (s);
}

int	main()
{
	size_t	num_elements = 5;
	size_t	element_size = sizeof(int);
	int	*array = (int *)ft_calloc(num_elements, element_size);
	if (array == NULL)
		printf("memory allocation failed\n");
	else
	{
		for(size_t i = 0; i < num_elements; i++)
		{
			printf("%d", array[i]);
		}
		free(array);
	}
	return (0);
}
*/
