/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <jlievano@student.42luxembourg.>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 01:02:22 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/19 01:08:23 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	t_list *temp_next;

	if (!lst)
		return ;
	temp_next = *lst;
	while (temp_next->next)
	{
		temp = temp_next;
		temp_next = temp->next;
		(*del)(temp->content);
		free(temp);
	}
}