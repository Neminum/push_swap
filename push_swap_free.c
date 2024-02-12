/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:59:28 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/12 19:11:32 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *a_head, t_list *b_head)
{
	t_list	*temp;

	if (a_head != NULL)
	{
		temp = a_head;
		temp->previous->next = NULL;
		while (temp->next != NULL)
		{
			temp = temp->next;
			free(temp->previous);
		}
		free(temp);
	}
	if (b_head != NULL)
	{
		temp = b_head;
		temp->previous->next = NULL;
		while (temp->next != NULL)
		{
			temp = temp->next;
			free(temp->previous);
		}
		free(temp);
	}
	exit (0);
}
