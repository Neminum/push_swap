/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobias <tobias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:09:14 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/05 21:48:38 by tobias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*previous;
	int				index;
}	t_list;

int		main(int argc, char **argv);
t_list	*arg_translator(t_list *a_head, int argc, char **argv);
t_list	*initialise(t_list *a_head, int size, char **temp);
t_list	*add_node(int value);
void	extract_node(t_list **head);
void	put_first(t_list **head, t_list *node);
void	put_last(t_list *head, t_list *node);
int		lstsize(t_list *head);
void	ft_printf_list(t_list *head);


int		swap(t_list *a, t_list *b);
void	ra(t_list **head);
void	rb(t_list **head);
void	rra(t_list **head);
void	rrb(t_list **head);
int		sa(t_list *a_head);
int		sb(t_list *a_head);
void	pa(t_list **a_head, t_list **b_head);
void	pb(t_list **a_head, t_list **b_head);

void	sort_three(t_list **head);
int		is_sorted(t_list *head);


#endif

