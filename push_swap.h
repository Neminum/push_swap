/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tobias <tobias@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:09:14 by tsurma            #+#    #+#             */
/*   Updated: 2024/02/12 23:54:53 by tobias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*previous;
	int				index;
}	t_list;

//startup
int		main(int argc, char **argv);
t_list	*arg_translator(t_list *a_head, int argc, char **argv);
t_list	*initialise(t_list *a_head, int size, char **temp, int allowfree);
t_list	*add_node(int value);
int		ft_atoi_err(const char *nptr, int allowfree, char** temp, t_list *a_head);
void	free_temp(char **temp);

void	extract_node(t_list **head);
void	put_first(t_list **head, t_list *node);
int		lstsize(t_list *head);
// void	ft_printf_list(t_list *head);
// void	ft_printf_index(t_list *head);

//instructions
void	swap(t_list *a, t_list *b);
void	ra(t_list **head);
void	rb(t_list **head);
void	rra(t_list **head);
void	rrb(t_list **head);
void	sa(t_list *a_head);
void	sb(t_list *a_head);
void	pa(t_list **a_head, t_list **b_head);
void	pb(t_list **a_head, t_list **b_head);

//sorting
void	sort_three(t_list **head);
void	sort_four(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list *head);
void	indexing(t_list *a_head);
t_list	*find_lowest(t_list *head);
t_list	*next_bigger(t_list *head);
int		find_diff(t_list *head, int index);
int		find_mindex(t_list **head, int val);
void	radix_sort(t_list **stack_a, t_list **stack_b);
int		get_max_bits(t_list **head);
void	sort_five(t_list **head_a, t_list **head_b);
void	check_doubles(t_list *head);
void	free_list(t_list *a_head, t_list *b_head);

#endif
