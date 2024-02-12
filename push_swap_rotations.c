/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:14:47 by tobias            #+#    #+#             */
/*   Updated: 2024/02/12 16:09:05 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotates list so the first value becomes the last
void	ra(t_list **head)
{
	*head = (*head)->next;
	ft_printf("ra\n");
}

void	rb(t_list **head)
{
	*head = (*head)->next;
	ft_printf("rb\n");
}

//rotates list so the last value becomes the first
void	rra(t_list **head)
{
	*head = (*head)->previous;
	ft_printf("rra\n");
}

void	rrb(t_list **head)
{
	*head = (*head)->previous;
	ft_printf("rrb\n");
}
