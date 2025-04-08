/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:59:52 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/08 12:51:44 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libs/libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int			*data;
	int			top;
	int			bottom;
	int			size;
}				t_stack;

typedef struct s_push_swap
{
	t_stack		a;
	t_stack		b;
	t_list		*op_list;
	int			checker_mode;
}				t_push_swap;

typedef enum e_operations
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}				t_operations;

// STACK_INIT
void			init_stack(t_stack *stack, int size);
void			fill_stack(t_stack *stack, int argc, char **argv);

// STACK_INIT_HELPER
int				count_numbers(char *str);
int				get_next_number(char **str);

// STACK_UTILS

int				next_up(t_stack *stack, int idx);
int				next_down(t_stack *stack, int idx);
int				current_size(t_stack *stk);
int				is_full(t_stack *stk);
int				value(t_stack *stk, int n);
void			cleanup(t_push_swap *ps);

// OP
const char		*op_to_string(t_operations *op);
void			error(t_push_swap *data);
t_operations	op_from(t_list *node);
void			print_operations(t_list *head);
void			save_op(t_push_swap *data, t_operations op);
void			optimize_operations(t_push_swap *data, t_list **head);
// STACK_OPERATIONS
void			push_a(t_push_swap *data);
void			push_b(t_push_swap *data);

void			r_rotate_a(t_push_swap *data);
void			r_rotate_b(t_push_swap *data);
void			r_rotate_ab(t_push_swap *data);

void			rotate_a(t_push_swap *data);
void			rotate_b(t_push_swap *data);
void			rotate_ab(t_push_swap *data);

void			swap_a(t_push_swap *data);
void			swap_b(t_push_swap *data);
void			swap_ab(t_push_swap *data);

#endif