#include "libft.h"

int ft_atoi(const char *str)
{
    int	i;
    int	is_negative;
    int	res;

    if (!str)
        return (0);
    i = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
    {
        i++;
    }
    is_negative = (str[i] == '-') ? -1 : 1;
    if (is_negative == -1 || str[i] == '+')
        i++;
    res = 0;
    while (str[i] >= '0' && str[i] <= '9')
        res = (res * 10) + (str[i++] - '0');
    return (res * is_negative);
}