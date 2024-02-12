/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:13:39 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/12 14:04:17 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **head_a, t_list **head_b)
{
	t_list	*temp_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	temp_a = *head_a;
	size = lstsize(temp_a);
	max_bits = get_max_bits(head_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			temp_a = *head_a;
			if (((temp_a->index >> i) & 1) == 1)
				ra(head_a);
			else
				pb(head_a, head_b);
		}
		while (lstsize(*head_b) != 0)
			pa(head_a, head_b);
		i++;
	}
}

int	get_max_bits(t_list **head)
{
	t_list	*temp;
	int		max;
	int		max_bits;

	temp = *head;
	max = temp->index;
	max_bits = 0;
	temp = temp->next;
	while (temp->next != *head)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
