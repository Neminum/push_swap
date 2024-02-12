/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push&swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:11:07 by tobias            #+#    #+#             */
/*   Updated: 2024/02/12 15:23:22 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swaps the values of the first 2 nodes in list
void	sa(t_list *head)
{
	if (head->next == head || !head)
	{
		ft_printf("Attempting to sa empty list or only one node");
		exit (0);
	}
	swap(head, head->next);
	ft_printf("sa\n");
}

void	sb(t_list *head)
{
	if (head->next == head || !head)
	{
		ft_printf("Attempting to sb empty list or only one node");
		exit (0);
	}
	swap(head, head->next);
	ft_printf("sb\n");
}

//Pushes from one stack to the other
void	pa(t_list **a_head, t_list **b_head)
{
	t_list	*temp;

	if (*b_head == NULL)
	{
		ft_printf("B is empty, push failed\n");
		exit(0);
	}
	temp = *b_head;
	extract_node(b_head);
	put_first(a_head, temp);
	ft_printf("pa\n");
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
	ft_printf("pb\n");
}

//swaps the values of two nodes
void	swap(t_list *a, t_list *b)
{
	if (!a || !b)
	{
		ft_printf("Trying to swap non-existant nodes.\n");
		exit (0);
	}
	a->value = a->value ^ b->value;
	b->value = a->value ^ b->value;
	a->value = a->value ^ b->value;
	a->index = a->index ^ b->index;
	b->index = a->index ^ b->index;
	a->index = a->index ^ b->index;
}
