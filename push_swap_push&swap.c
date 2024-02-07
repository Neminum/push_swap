/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push&swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobias <tobias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:11:07 by tobias            #+#    #+#             */
/*   Updated: 2024/02/05 17:07:23 by tobias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

//swaps the values of the first 2 nodes in list
int	sa(t_list *head)
{
	if (head->next == head)
		return (1);
	swap(head, head->next);
	return (0);
}

int	sb(t_list *head)
{
	if (head->next == head)
		return (1);
	swap(head, head->next);
	return (0);
}

//Pushes from one stack to the other
void	pa(t_list **a_head, t_list **b_head)
{
	t_list	*temp;

	if (*a_head == NULL)
	{
		ft_printf("B is empty, push failed\n");
		exit(0);
	}
	temp = *a_head;
	extract_node(a_head);
	put_first(b_head, temp);
}

void	pb(t_list **a_head, t_list **b_head)
{
	t_list	*temp;

	if (*a_head == NULL)
	{
		ft_printf("A is empty, push failed\n");
		exit(0);
	}
	temp = *a_head;
	extract_node(a_head);
	put_first(b_head, temp);
}

//swaps the values of two nodes
int	swap(t_list *a, t_list *b)
{
	if (!a || !b)
		return (-1);
	a->value = a->value ^ b->value;
	b->value = a->value ^ b->value;
	a->value = a->value ^ b->value;
	return (0);
}


