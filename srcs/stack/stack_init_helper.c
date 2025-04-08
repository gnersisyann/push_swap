/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:28 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/08 15:45:04 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int	count_numbers(char *str)
{
	int	i;
	int	count;
	int	in_number;

	i = 0;
	count = 0;
	in_number = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !in_number)
		{
			in_number = 1;
			count++;
		}
		else if (str[i] == ' ')
			in_number = 0;
		i++;
	}
	return (count);
}

int	get_next_number(char **str)
{
	int		num;
	char	*start;

	if (!str || !*str)
		return (0);
	while (**str == ' ')
		(*str)++;
	start = *str;
	if (!**str)
		return (0);
	while (**str && **str != ' ')
		(*str)++;
	if (**str)
	{
		**str = '\0';
		num = ft_atoi(start);
		**str = ' ';
		(*str)++;
	}
	else
	{
		num = ft_atoi(start);
	}
	return (num);
}

int	get_stack_size(int argc, char **argv)
{
	if (argc == 2)
		return (count_numbers(argv[1]));
	return (argc - 1);
}

void	cleanup(t_push_swap *ps)
{
	t_list	*tmp;

	if (ps->a.data)
		free(ps->a.data);
	if (ps->b.data)
		free(ps->b.data);
	while (ps->op_list)
	{
		tmp = ps->op_list->next;
		free(ps->op_list->content);
		free(ps->op_list);
		ps->op_list = tmp;
	}
}
