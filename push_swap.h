/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsurma <tsurma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:09:14 by tsurma            #+#    #+#             */
/*   Updated: 2024/01/31 17:17:57 by tsurma           ###   ########.fr       */
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
}	t_list;

static t_list	*arg_translator(t_list *a_head, int argc, char **argv);
int	main(int argc, char **argv);
t_list	*add_node(int value);
void	put_last(t_list *head, t_list *node);
int	swap(t_list *a, t_list *b);
int	sa(t_list *a_head);
void	ra(t_list **head);
void	rra(t_list **head);
void	printf_list(t_list *head);
void	put_first(t_list **head, t_list *node);



#endif

