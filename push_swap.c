/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:08:27 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/12 19:13:06 by tsurma           ###   ########.fr       */
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
		return (0);
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

//takes the argument(s), translates them into ints, and adds them into the list.
t_list	*arg_translator(t_list *a_head, int argc, char **argv)
{
	char	**temp;

	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		argc = 0;
		while (temp[argc] != NULL)
			++argc;
		if (argc == 0)
			free_list(a_head, NULL);
	}
	else
	{
		temp = ++argv;
		--argc;
	}
	return (initialise(a_head, argc, temp));
}

//initialises the list for the first time and adds the arguments
t_list	*initialise(t_list *a_head, int size, char **temp)
{
	t_list	*new;

	new = add_node(ft_atoi_err(temp[--size]));
	new->next = new;
	new->previous = new;
	a_head = new;
	while (size != 0)
	{
		new = add_node(ft_atoi_err(temp[size - 1]));
		put_first(&a_head, new);
		size--;
	}
	return (a_head);
}

int	ft_atoi_err(const char *nptr)
{
	int			i;
	int			m;
	long int	r;

	i = 0;
	r = 0;
	m = 0;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			m = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		r = (r * 10) + (nptr[i++] - 48);
	if (nptr[i] != 0 || r > __INT_MAX__ || (-r) < (-__INT_MAX__ - 1))
	{
		write(2, "Error\n", 7);
		exit (0);
	}
	if (m == 1)
		return (-r);
	return (r);
}

void	check_doubles(t_list *head)
{
	t_list	*tempi;
	t_list	*tempj;

	tempj = head->next;
	while (tempj != head)
	{
		tempi = tempj->next;
		while (tempi != tempj)
		{
			if (tempi->value == tempj->value)
			{
				write(2, "Error\n", 7);
				free_list(head, NULL);
			}
			tempi = tempi->next;
		}
		tempj = tempj->next;
	}
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
