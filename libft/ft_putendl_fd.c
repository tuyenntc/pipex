#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	size_t	len;

	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}
/*
int main(void)
{
    char *test_strings[] = {
        "Hello, World!",
        "Testing ft_putendl_fd.",
        NULL,
        "Another test."
    };
    int fd = 1;
    for (int i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); ++i)
    {
        ft_putendl_fd(test_strings[i], fd);
    }

    return 0;
}
*/
