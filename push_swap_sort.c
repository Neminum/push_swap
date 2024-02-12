/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:03:44 by tobias            #+#    #+#             */
/*   Updated: 2024/02/12 16:09:02 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *head)
{
	t_list	*temp;

	if (head == NULL)
		return (-1);
	temp = head;
	while (temp->next != head)
	{
		if (temp->next->value < temp->value)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

void	sort_three(t_list **head)
{
	if ((*head)->next->value > (*head)->value
		&& (*head)->next->value > (*head)->previous->value)
	{
		rra(head);
		if (is_sorted(*head) == -1)
			sa(*head);
	}
	else if ((*head)->previous->value < (*head)->value
		&& (*head)->previous->value > (*head)->next->value)
		ra(head);
	else
		sa(*head);
	if (is_sorted(*head) == 0)
		return ;
	rra(head);
}

void	sort_four(t_list **head_a, t_list **head_b)
{
	int	distance;

	distance = find_diff(*head_a, find_mindex(head_a, -1));
	if (distance == 1)
		ra(head_a);
	else if (distance == 2)
	{
		ra(head_a);
		ra(head_a);
	}
	else if (distance == 3)
		rra(head_a);
	if (is_sorted(*head_a) == 0)
		return ;
	pb(head_a, head_b);
	sort_three(head_a);
	pa(head_a, head_b);
}

void	sort_five(t_list **head_a, t_list **head_b)
{
	int	distance;

	distance = find_diff(*head_a, find_mindex(head_a, -1));
	if (distance == 1)
		ra(head_a);
	else if (distance == 2)
	{
		ra(head_a);
		ra(head_a);
	}
	else if (distance == 3)
	{
		rra(head_a);
		rra(head_a);
	}
	else if (distance == 4)
		rra(head_a);
	if (is_sorted(*head_a) == 0)
		return ;
	pb(head_a, head_b);
	sort_four(head_a, head_b);
	pa(head_a, head_b);
}
