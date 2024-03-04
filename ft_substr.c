/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:59:12 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/04 01:00:18 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!str)
		return (NULL);
	i = 0;
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = str[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
