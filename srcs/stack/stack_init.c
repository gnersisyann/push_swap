/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:26 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/05 15:13:38 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

void	rank_stack(int *nums, int *ranks, t_stack *stack)
{
	int	i;
	int	j;
	int	rank;

	i = -1;
	while (++i < stack->size)
	{
		rank = 1;
		j = -1;
		while (++j < stack->size)
			if (nums[i] > nums[j])
				rank++;
		ranks[i] = rank;
	}
	i = -1;
	while (++i < stack->size)
		stack->data[i] = ranks[i];
	return (free(nums), free(ranks));
}

void	init_stack(t_stack *stack, int size)
{
	if (!stack)
		return ;
	stack->size = size;
	stack->top = 0;
	stack->bottom = 0;
	if (size <= 0)
	{
		stack->data = NULL;
		return ;
	}
	stack->data = (int *)malloc(sizeof(int) * size);
	if (!stack->data)
		return ;
	ft_bzero(stack->data, sizeof(int) * size);
}

static void	fill_stack_helper(t_stack *stack, int argc, char **argv)
{
	int	i;

	if (argc <= 1 || !stack->data)
		return ;
	i = -1;
	while (++i < stack->size)
		stack->data[i] = ft_atoi(argv[i + 1]);
	if (stack->size > 0)
	{
		stack->top = 0;
		stack->bottom = stack->size - 1;
	}
}

static int	allocate_and_fill_from_string(t_stack *stack, char *str)
{
	char	*tmp;
	char	*tmp_ptr;
	int		i;

	tmp = ft_strdup(str);
	if (!tmp)
		return (0);
	tmp_ptr = tmp;
	i = 0;
	while (i < stack->size)
		stack->data[i++] = get_next_number(&tmp_ptr);
	free(tmp);
	if (stack->size > 0)
	{
		stack->top = 0;
		stack->bottom = stack->size - 1;
	}
	return (1);
}

void	fill_stack(t_stack *stack, int argc, char **argv)
{
	int	*nums;
	int	*ranks;

	if (!stack || !stack->data)
		return ;
	if (argc == 2)
	{
		if (!allocate_and_fill_from_string(stack, argv[1]))
			return ;
	}
	else
		fill_stack_helper(stack, argc, argv);
	nums = (int *)malloc(sizeof(int) * stack->size);
	if (!nums)
		return ;
	ft_memcpy(nums, stack->data, sizeof(int) * stack->size);
	ranks = (int *)malloc(sizeof(int) * stack->size);
	if (!ranks)
		return (free(nums));
	rank_stack(nums, ranks, stack);
}
