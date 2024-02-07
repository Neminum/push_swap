/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_indexing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:56:41 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/07 16:57:32 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_list *a_head)
{
	int		index;
	t_list	*temp;

	temp = NULL;
	index = 0;
	temp = find_lowest(a_head);

	while (temp != NULL)
	{
		temp->index = index;
		temp = next_bigger(temp);
		++index;
	}
}

t_list	*next_bigger(t_list *head)
{
	t_list	*tempmin;
	t_list	*temp;

	if (head == NULL)
	{
		ft_printf("Err in indexing, got empty head");
		exit (0);
	}
	temp = head->next;
	tempmin = NULL;
	while (temp != head)
	{
		if (tempmin == NULL && temp->value > head->value)
			tempmin = temp;
		else if (tempmin != NULL && temp->value < tempmin->value
			&& temp->value > head->value)
			tempmin = temp;
		temp = temp->next;
	}
	return (tempmin);
}

t_list	*find_lowest(t_list *head)
{
	t_list	*tempmin;
	t_list	*temp;

	temp = head->next;
	tempmin = head;
	while (temp != head)
	{
		if (temp->value < tempmin->value)
			tempmin = temp;
		temp = temp->next;
	}
	if (temp->value < tempmin->value)
		tempmin = temp;
	return (tempmin);
}
