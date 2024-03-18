#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	write(fd, s,ft_strlen(s));
}
/*
int main(void)
{
    char *test_strings[] = {
        "Hello, World!",
        "Testing ft_putstr_fd.",
        NULL,
        "Another test."
    };

    int fd = 1;

    for (int i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); ++i)
    {
        ft_putstr_fd(test_strings[i], fd);
        write(fd, "\n", 1);
    }

    return 0;
}
*/
/*
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
*/
