/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:11:32 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/14 12:11:55 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//takes the argument(s), translates them into ints, and adds them into the list.
t_list	*arg_translator(t_list *a_head, int argc, char **argv)
{
	char	**temp;
	t_list	*output;

	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		argc = 0;
		while (temp[argc] != NULL)
			++argc;
		if (argc == 0)
		{
			free_temp(temp);
			free_list(a_head, NULL);
		}
		output = initialise(a_head, argc, temp, 1);
	}
	else
	{
		temp = ++argv;
		--argc;
		output = initialise(a_head, argc, temp, 0);
	}
	return (output);
}

//initialises the list for the first time and adds the arguments
t_list	*initialise(t_list *a_head, int size, char **temp, int allowfree)
{
	t_list	*new;

	new = add_node(ft_atoi_err(temp[--size], allowfree, temp, a_head));
	new->next = new;
	new->previous = new;
	a_head = new;
	while (size != 0)
	{
		new = add_node(ft_atoi_err(temp[size - 1], allowfree, temp, a_head));
		put_first(&a_head, new);
		size--;
	}
	if (allowfree == 1)
		free_temp(temp);
	return (a_head);
}

int	ft_atoi_err(char *nptr, int af, char **temp, t_list *a_head)
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
		ft_atoi_err_err(temp, a_head, af);
	if (m == 1)
		return (-r);
	return (r);
}

void	ft_atoi_err_err(char **temp, t_list *a_head, int af)
{
	write(2, "Error\n", 7);
	if (af == 1)
		free_temp(temp);
	free_list(a_head, NULL);
	exit (0);
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
