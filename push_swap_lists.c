/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:34:20 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/12 14:37:29 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_list *head)
{
	t_list	*temp;
	int		i;

	if (head == NULL)
		return (0);
	i = 1;
	temp = head;
	while (temp->next != head)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

//adds a node to the list, at the first position
void	put_first(t_list **head, t_list *node)
{
	if (*head == NULL)
	{
		*head = node;
		(*head)->previous = *head;
		(*head)->next = *head;
		return ;
	}
	node->previous = (*head)->previous;
	node->next = (*head);
	(*head)->previous->next = node;
	(*head)->previous = node;
	(*head) = node;
}

//takes a node out of continuity of its list
void	extract_node(t_list **head)
{
	if ((*head)->next == *head)
	{
		(*head) = NULL;
		return ;
	}
	(*head)->previous->next = (*head)->next;
	(*head)->next->previous = (*head)->previous;
	*head = (*head)->next;
}

//creates a new node with a pointer
t_list	*add_node(int value)
{
	t_list	*node;

	node = ft_calloc(1, sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	return (node);
}
