/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:59:52 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:59:52 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../libs/libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int		*data;
	int		top;
	int		bottom;
	int		size;
}			t_stack;

typedef struct s_push_swap
{
	t_stack	a;
	t_stack	b;
	t_list	*op_list;
}			t_push_swap;

// STACK_INIT
void		init_stack(t_stack *stack, int argc, char **argv);

// STACK_INIT_HELPER
int			count_numbers(char *str);
int			get_next_number(char **str);

#endif