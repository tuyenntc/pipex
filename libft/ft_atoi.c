#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
/*
int main() {
    const char *str1 = "12345";
    const char *str2 = "-6789";
    const char *str3 = "  +42";
    const char *str4 = "   -789";

    int num1 = ft_atoi(str1);
    int num2 = ft_atoi(str2);
    int num3 = ft_atoi(str3);
    int num4 = ft_atoi(str4);

    printf("String: %s, Integer: %d\n", str1, num1);
    printf("String: %s, Integer: %d\n", str2, num2);
    printf("String: %s, Integer: %d\n", str3, num3);
    printf("String: %s, Integer: %d\n", str4, num4);

    return 0;
}*/
