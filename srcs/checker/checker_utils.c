/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:44:12 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/08 18:05:29 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	err(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	init_checker(t_push_swap *ps, int argc, char **argv)
{
	int	stack_size;

	validate_input(argc, argv);
	stack_size = get_stack_size(argc, argv);
	init_stack(&ps->a, stack_size);
	init_stack(&ps->b, stack_size);
	ps->op_list = NULL;
	ps->checker_mode = 1;
	fill_stack(&ps->a, argc, argv);
}

static void	checker_sort_helper(t_push_swap *ps, char *op_arr, int *step)
{
	if (ft_strncmp(op_arr, "rra", 3) == 0)
	{
		r_rotate_a(ps);
		++(*step);
	}
	else if (ft_strncmp(op_arr, "rrb", 3) == 0)
	{
		r_rotate_b(ps);
		++(*step);
	}
	else if (ft_strncmp(op_arr, "rrr", 3) == 0)
	{
		r_rotate_ab(ps);
		++(*step);
	}
	else if (ft_strncmp(op_arr, "ra", 2) == 0)
		rotate_a(ps);
	else if (ft_strncmp(op_arr, "rb", 2) == 0)
		rotate_b(ps);
	else if (ft_strncmp(op_arr, "rr", 2) == 0)
		rotate_ab(ps);
}

void	checker_sort(t_push_swap *ps, char *op_arr)
{
	int	step;

	while (*op_arr)
	{
		step = 3;
		if (ft_strncmp(op_arr, "pa", 2) == 0)
			push_a(ps);
		else if (ft_strncmp(op_arr, "pb", 2) == 0)
			push_b(ps);
		else if (ft_strncmp(op_arr, "sa", 2) == 0)
			swap_a(ps);
		else if (ft_strncmp(op_arr, "sb", 2) == 0)
			swap_b(ps);
		else if (ft_strncmp(op_arr, "ss", 2) == 0)
			swap_ab(ps);
		else
			checker_sort_helper(ps, op_arr, &step);
		op_arr += step;
	}
}

void	fill_op(char buf[BUFSIZE + 1], char **op_arr, char **op_arr_orig)
{
	char	*temp;
	int		read_bytes;

	while (1)
	{
		read_bytes = read(0, buf, BUFSIZE);
		if (read_bytes < 0)
		{
			free(*op_arr_orig);
			err();
		}
		else if (read_bytes == 0)
			break ;
		buf[read_bytes] = '\0';
		temp = ft_strjoin(*op_arr, buf);
		if (!temp)
		{
			free(*op_arr_orig);
			err();
		}
		*op_arr = temp;
	}
}
