#include <stdio.h>
#include "libft.h"
/*
int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list actual_element;

	if (!lst)
		return (0);	
	actual_element = *lst;
	i = 0;
	printf("N before while: %d \n", (int)i);
	while(actual_element.next != NULL)
	{
		i++;
		printf("N : %d      \n", (int)i);
		actual_element = *actual_element.next;
	}	
	printf("returning -> %d \n", (int)i);
	return (i);
}
*/
int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
