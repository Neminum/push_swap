/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:08:27 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/14 12:11:22 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a_head;
	t_list	*b_head;

	a_head = NULL;
	b_head = NULL;
	if (argc < 2)
		return (-1);
	a_head = arg_translator(a_head, argc, argv);
	check_doubles(a_head);
	if (is_sorted(a_head) == 0)
		free_list(a_head, b_head);
	argc = lstsize(a_head);
	indexing(a_head);
	if (argc == 2)
		sa(a_head);
	if (argc == 3)
		sort_three(&a_head);
	if (argc == 4)
		sort_four(&a_head, &b_head);
	if (argc == 5)
		sort_five(&a_head, &b_head);
	if (argc >= 6)
		radix_sort(&a_head, &b_head);
	free_list(a_head, b_head);
	return (0);
}

// void	ft_printf_list(t_list *head)
// {
// 	t_list	*temp;

// 	if (head == NULL)
// 		return ;
// 	temp = head;
// 	ft_printf("%d ", temp->value);
// 	temp = temp->next;
// 	while (temp != head)
// 	{
// 		ft_printf("%d ", temp->value);
// 		temp = temp->next;
// 	}
// 	ft_printf("\n");
// }

// void	ft_printf_index(t_list *head)
// {
// 	t_list	*temp;

// 	if (head == NULL)
// 		return ;
// 	temp = head;
// 	ft_printf("%d ", temp->index);
// 	temp = temp->next;
// 	while (temp != head)
// 	{
// 		ft_printf("%d ", temp->index);
// 		temp = temp->next;
// 	}
// 	ft_printf("\n");
// }
