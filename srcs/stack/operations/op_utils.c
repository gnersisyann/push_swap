/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 21:09:02 by ugerkens          #+#    #+#             */
/*   Updated: 2025/04/08 12:50:05 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/stack.h"

void	save_op(t_push_swap *data, t_operations op)
{
	t_list			*new;
	t_operations	*op_ptr;

	op_ptr = malloc(sizeof(t_operations));
	if (!op_ptr)
		error(data);
	*op_ptr = op;
	new = ft_lstnew(op_ptr);
	if (!new)
	{
		free(op_ptr);
		error(data);
	}
	ft_lstadd_back(&data->op_list, new);
}

void	print_operations(t_list *head)
{
	t_list		*reader;
	const char	*str;

	reader = head;
	while (reader)
	{
		str = op_to_string((t_operations *)reader->content);
		if (ft_strncmp(str, "null_op", ft_strlen(str)) != 0)
		{
			ft_putstr_fd((char *)str, 1);
			ft_putstr_fd("\n", 1);
		}
		reader = reader->next;
	}
}

const char	*op_to_string(t_operations *op)
{
	if (*op == sa)
		return ("sa");
	if (*op == sb)
		return ("sb");
	if (*op == ss)
		return ("ss");
	if (*op == pa)
		return ("pa");
	if (*op == pb)
		return ("pb");
	if (*op == ra)
		return ("ra");
	if (*op == rb)
		return ("rb");
	if (*op == rr)
		return ("rr");
	if (*op == rra)
		return ("rra");
	if (*op == rrb)
		return ("rrb");
	if (*op == rrr)
		return ("rrr");
	return ("unknown op");
}

void	error(t_push_swap *data)
{
	cleanup(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}