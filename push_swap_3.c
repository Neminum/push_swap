/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:03:44 by tobias            #+#    #+#             */
/*   Updated: 2024/02/07 17:29:14 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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
	if (is_sorted(*head) == -1)
		rra(head);
}



void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = find_diff(*stack_a, find_mindex(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(*stack_a) == 0)
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}



int	find_diff(t_list *head, int index)
{
	t_list	*temp;
	int		diff;


	if (head->index == index)
		return (0);
	temp = head->next;
	diff = 1;
	while (temp != head)
	{
		if (temp->index == index)
			return (diff);
		temp = temp->next;
		++diff;
	}
	ft_printf("Couldnt find DIFF");
	exit (0);
}

int	find_mindex(t_list **head, int val)
{
	t_list	*temp;
	int		mindex;

	mindex = (*head)->index;
	temp = (*head)->next;
	while (temp != *head)
	{
		if ((temp->index < mindex) && temp->index != val)
			mindex = temp->index;
		temp = temp->next;
	}
	return (mindex);
}
