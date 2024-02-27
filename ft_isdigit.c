#include "libft.h"

int fi_isdigit(int digit)
{
    if (digit >= '0' && digit <= '9')
        return (1);
    return (0);
}