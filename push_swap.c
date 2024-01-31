/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:08:27 by tsurma            #+#    #+#             */
/*   Updated: 2024/01/31 17:40:03 by tsurma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*a_head;
	t_list	*b_head;

	a_head = NULL;
	b_head = NULL;
	if (argc < 2)
		return (-1);
	a_head = arg_translator(a_head, argc, argv);



	printf_list(a_head);

}

void	printf_list(t_list *head)
{
	t_list	*temp;

	temp = head;
	printf("%d ", temp->value);
	temp = temp->next;
	while (temp != head)
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
}


//takes the argument(s), translates them into ints, and adds them into the list.
static t_list	*arg_translator(t_list *a_head, int argc, char **argv)
{
	char	**temp;
	int		i;
	t_list	*new;

	i = -1;
	if (argc == 2)
		temp = ft_split(argv[1], ' ');
	else
		temp = ++argv;
	new = add_node(ft_atoi(temp[++i]));
	new->next = new;
	new->previous = new;
	a_head = new;
	while (temp[++i])
	{
		new = add_node(ft_atoi(temp[i]));
		put_last(a_head, new);
	}
	return (a_head);
}

//creates a new node with a pointer
t_list	*add_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->previous = NULL;
	node->next = NULL;
	return (node);
}

void	pb(t_list **a_head, t_list **b_head)
{
	t_list	*temp;

	temp = *a_head;
	extract_node(a_head, temp);
	put_first(b_head, temp);
}

void	extract_node(t_list **head, t_list *node)
{
	node->previous->next = node->next;
	node->next->previous = node->previous;
	(*head) = node->next;
}

//adds a node to the list, at the last position
void	put_last(t_list *head, t_list *node)
{
	t_list	*temp;

	temp = head;
	while (temp->next != head)
		temp = temp->next;
	temp->next = node;
	node->next = head;
	node->previous = temp;
	head->previous = node;
}

//adds a node to the list, at the first position
void	put_first(t_list **head, t_list *node)
{
	node->previous = (*head)->previous;
	node->next = (*head);
	(*head)->previous->next = node;
	(*head)->previous = node;
	(*head) = node;
}

//swaps the values of two nodes
int	swap(t_list *a, t_list *b)
{
	if (!a || !b)
		return (-1);
	a->value = a->value ^ b->value;
	b->value = a->value ^ b->value;
	a->value = a->value ^ b->value;
	return (0);
}

//swaps the values of the first 2 nodes in list
int	sa(t_list *head)
{
	if (head->next == head)
		return (1);
	swap(head, head->next);
	return (0);
}

//rotates list so the first value becomes the last
void	ra(t_list **head)
{
	*head = (*head)->next;
}

//rotates list so the last value becomes the first
void	rra(t_list **head)
{
	*head = (*head)->previous;
}
