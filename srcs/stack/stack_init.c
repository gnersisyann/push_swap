/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:26 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:46:27 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

static void	init_stack_helper(t_stack *stack, int argc, char **argv)
{
	int	i;

	if (argc > 2)
	{
		stack->size = argc - 1;
		stack->data = (int *)malloc(sizeof(int) * stack->size);
		if (!stack->data)
			return ;
		i = -1;
		while (++i < stack->size)
			stack->data[i] = ft_atoi(argv[i + 1]);
	}
	else
	{
		stack->size = 0;
		stack->data = NULL;
		return ;
	}
	if (stack->size > 0)
	{
		stack->top = stack->data[0];
		stack->bottom = stack->data[stack->size - 1];
	}
}

static int	allocate_and_fill_stack(t_stack *stack, char *str)
{
	char	*tmp;
	char	*tmp_ptr;
	int		i;

	stack->size = count_numbers(str);
	stack->data = (int *)malloc(sizeof(int) * stack->size);
	if (!stack->data)
		return (0);
	tmp = ft_strdup(str);
	if (!tmp)
	{
		free(stack->data);
		return (0);
	}
	tmp_ptr = tmp;
	i = 0;
	while (i < stack->size)
		stack->data[i++] = get_next_number(&tmp_ptr);
	free(tmp);
	return (1);
}

void	init_stack(t_stack *stack, int argc, char **argv)
{
	if (argc == 2)
	{
		if (!allocate_and_fill_stack(stack, argv[1]))
			return ;
		if (stack->size > 0)
		{
			stack->top = stack->data[0];
			stack->bottom = stack->data[stack->size - 1];
		}
	}
	else
		init_stack_helper(stack, argc, argv);
}
