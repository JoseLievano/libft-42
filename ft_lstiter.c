/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 08:51:47 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/19 08:59:52 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (* f)(void *))
{
	t_list *temp;

	if (!lst)
		return ;
	temp = lst;
	while (temp)
	{
		(*f)(temp->content);
		temp = lst->next;
	}
}