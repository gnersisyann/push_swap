/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_optimize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:44:40 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/08 15:44:41 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/stack.h"

t_operations	to_op(void *content)
{
	return (*(t_operations *)content);
}

void	add_optimized(t_push_swap *data, t_list *current,
		t_list **optimized_list)
{
	t_operations	*op_ptr;

	op_ptr = malloc(sizeof(t_operations));
	if (!op_ptr)
		error(data);
	*op_ptr = to_op(current->content);
	ft_lstadd_back(optimized_list, ft_lstnew(op_ptr));
}

int	check(t_push_swap *data, t_list **optimized_list, t_list *head,
		t_operations op[3])
{
	t_operations	*op_ptr;

	if ((to_op(head->content) == op[0] && to_op(head->next->content) == op[1])
		|| (to_op(head->content) == op[1]
			&& to_op(head->next->content) == op[0]))
	{
		op_ptr = malloc(sizeof(t_operations));
		if (!op_ptr)
			error(data);
		*op_ptr = op[2];
		ft_lstadd_back(optimized_list, ft_lstnew(op_ptr));
		return (1);
	}
	return (0);
}

void	optimize_operations(t_push_swap *data, t_list **head)
{
	t_list				*optimized_list;
	t_list				*current;
	static t_operations	rotate[3] = {ra, rb, rr};
	static t_operations	r_rotate[3] = {rra, rrb, rrr};
	static t_operations	swap[3] = {sa, sb, ss};

	optimized_list = NULL;
	current = *head;
	while (current && current->next)
	{
		if (check(data, &optimized_list, current, rotate) || check(data,
				&optimized_list, current, r_rotate) || check(data,
				&optimized_list, current, swap))
		{
			current = current->next->next;
			continue ;
		}
		add_optimized(data, current, &optimized_list);
		current = current->next;
	}
	if (current)
		add_optimized(data, current, &optimized_list);
	ft_lstclear(head, free);
	data->op_list = optimized_list;
}
