/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobias <tobias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:14:47 by tobias            #+#    #+#             */
/*   Updated: 2024/02/05 19:56:44 by tobias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

//rotates list so the first value becomes the last
void	ra(t_list **head)
{
	*head = (*head)->next;
}

void	rb(t_list **head)
{
	*head = (*head)->next;
}

//rotates list so the last value becomes the first
void	rra(t_list **head)
{
	*head = (*head)->previous;
}

void	rrb(t_list **head)
{
	*head = (*head)->previous;
}
