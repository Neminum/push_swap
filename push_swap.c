/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobias <tobias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:08:27 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/05 21:51:41 by tobias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_list	*a_head;
	t_list	*b_head;

	a_head = NULL;
	b_head = NULL;
	if (argc < 2)
		return (-1);
	a_head = arg_translator(a_head, argc, argv);

	ft_printf_list(a_head);
	ft_printf_list(b_head);

	// ft_printf("Size A: %d\n", lstsize(a_head));
	return (0);
}

void	ft_printf_list(t_list *head)
{
	t_list	*temp;

	if (head == NULL)
		return ;
	temp = head;
	ft_printf("%d ", temp->value);
	temp = temp->next;
	while (temp != head)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
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

	new = add_node(ft_atoi(temp[--size]));
	new->next = new;
	new->previous = new;
	a_head = new;
	while (size != 0)
	{
		new = add_node(ft_atoi(temp[size - 1]));
		put_first(&a_head, new);
		size--;
	}
	return(a_head);
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

int		lstsize(t_list *head)
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

void	bubblesort(t_list **head)
{
	
}