#include "libft.h"

void    ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main(void)
{
    // Test characters
    char test_chars[] = {'A', 'b', '5', '\n', '!'};

    // File descriptor for standard output
    int fd = 1;

    // Testing ft_putchar_fd
    for (int i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); ++i)
    {
        ft_putchar_fd(test_chars[i], fd);
    }

    return 0;
}
*/
