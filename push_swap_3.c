/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobias <tobias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:03:44 by tobias            #+#    #+#             */
/*   Updated: 2024/02/05 21:50:24 by tobias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	is_sorted(t_list *head)
{
	t_list	*temp;
	
	if (head == NULL)
		return (0);
	
	temp = head;
	while (temp->next != head)
	{
		if (temp->next->value < temp->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	sort_three(t_list **head)
{
	if ((*head)->next->value > (*head)->value && (*head)->next->value > (*head)->previous->value)
	{
		rra(head);
		if (is_sorted(*head) == 1)
			sa(*head);
	}
}


// 1 2 3	sorted
// 2 3 1	rra
// 1 3 2	rra sa

// 3 1 2	ra
// 3 2 1	sa rra
// 2 1 3	sa