/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 21:10:50 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/03 21:30:24 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int number)
{
	int	count;

	if (number == 0)
	{
		count = 1;
	}
	else
	{
		count = 0;
	}
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static int	is_negative(int number)
{
	if (number < 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

static char	*memory_allocation(int amount_digits, int is_negative)
{
	char	*str;

	if (is_negative)
	{
		str = (char *)malloc(sizeof(char) * (amount_digits + 2));
		if (!str)
			return (NULL);
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (amount_digits + 1));
		if (!str)
			return (NULL);
	}
	return (str);
}

//Static function that gets an amount of digits, a pointer to a
//string and the number to convert
static char	*get_str(char *str, int number, int amount_digits, int is_negative)
{
	int	i;

	if (is_negative)
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
    	//int i = is_negative ? 1 : 0; // Start index at 1 if negative to leave space for '-'

    // Add the negative sign if needed
	if (is_negative)
        	str[0] = '-';

    // Convert number to string from the end
    str[amount_digits + i] = '\0'; // Place the null terminator
    while (amount_digits > 0)
    {
        str[amount_digits + i - 1] = (number % 10) + '0'; // Convert last digit to char
        number /= 10; // Remove last digit from number
        amount_digits--;
    }

    return str;
}

char		*ft_itoa(int n)
{
    size_t amount_digits;
    char *str;
    int neg_flag;

    if (n == -2147483648)
        return ft_strdup("-2147483648");

    neg_flag = is_negative(n); // Store negativity before changing n
    if (neg_flag)
        n *= -1; // Make n positive to count the digits and build the string

    amount_digits = digit_count(n);
    str = memory_allocation(amount_digits, neg_flag); // Allocate memory including space for negative sign if necessary
    if (!str)
        return NULL;

    return get_str(str, n, amount_digits, neg_flag); // Use the stored neg_flag to handle the negative sign
}
