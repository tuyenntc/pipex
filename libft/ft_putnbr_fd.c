#include "libft.h"
/*
void	ft_putnbr_fd(int n, int fd)

{
	char	digit;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n <= 10)
		ft_putnbr_fd(n / 10, fd);
	digit = '0' + (n % 10);
	write(fd, &digit, 1);
}

if (n == -2147483648)
{
	ft_putchar_fd('-');
	ft_putchar_fd('2');
	ft_putnbr(147483648);
}

*/


void	ft_putnbr_fd(int n, int fd)
{
	char buf[12];
	int	i;

	i = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n > 0)
	{
		buf[i++] = n % 10 + '0';
		n /= 10;
	}
	while (i > 0)
	{
		write(fd, &buf[--i], 1);
	}
}
/*
void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n / 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
*/
/*
int main(void)
{
    int fd = 1;  // file descriptor 1 for standard output
    int test_values[] = {0, -42, 12345, -2147483648, 2147483647};

    for (int i = 0; i < sizeof(test_values) / sizeof(test_values[0]); ++i)
    {
        ft_putnbr_fd(test_values[i], fd);
        write(fd, "\n", 1);  //for readability
    }

    return 0;
}
*/
