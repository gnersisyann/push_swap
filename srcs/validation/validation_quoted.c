/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_quoted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:08 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:46:09 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_valid_quoted_numbers_helper1(int *space_found, int *i, char *str)
{
	int		j;
	char	*num_start;
	char	temp;

	if (*i == 0 || *space_found || str[*i - 1] == ' ')
	{
		num_start = &str[*i];
		j = 0;
		while (str[*i + j] && str[*i + j] != ' ')
			j++;
		temp = str[*i + j];
		str[*i + j] = '\0';
		if (!is_number(num_start) || !is_within_int_limits(num_start))
		{
			str[*i + j] = temp;
			return (1);
		}
		str[*i + j] = temp;
		*i += j;
		*space_found = 0;
	}
	else
		(*i)++;
	return (0);
}

static int	edge_checks(char *str, int *i, int *space_found)
{
	if (!str || !*str)
		return (1);
	*i = 0;
	*space_found = 0;
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	if (!str[*i])
		return (1);
	return (0);
}

static int	is_valid_quoted_numbers_helper2(char *str, int *count)
{
	int	*nums;

	nums = extract_numbers_from_string(str, count);
	if (!nums)
		return (1);
	if (*count == 0 || has_duplicates(nums, *count))
	{
		free(nums);
		return (1);
	}
	free(nums);
	return (0);
}

int	is_valid_quoted_numbers(char *str)
{
	int	i;
	int	space_found;
	int	count;

	if (edge_checks(str, &i, &space_found))
		return (0);
	while (str[i])
	{
		if (ft_isdigit(str[i]) || (str[i] == '-' || str[i] == '+'))
		{
			if (is_valid_quoted_numbers_helper1(&space_found, &i, str))
				return (0);
		}
		else if (str[i++] == ' ')
			space_found = 1;
		else
			return (0);
	}
	if (is_valid_quoted_numbers_helper2(str, &count))
		return (0);
	return (1);
}
