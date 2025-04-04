/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_limits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:18 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 16:01:02 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <limits.h>

static int	handle_sign_and_spaces(char *str, int *i, int *sign)
{
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'
			|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r'))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	return (*i);
}

int	is_within_int_limits(char *str)
{
	long	num;
	int		sign;
	int		i;

	if (!str || !*str)
		return (0);
	num = 0;
	sign = 1;
	i = 0;
	i = handle_sign_and_spaces(str, &i, &sign);
	if (!str[i] || !ft_isdigit(str[i]))
		return (0);
	while (str[i] && ft_isdigit(str[i]))
	{
		if ((sign == 1 && (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i]
						- '0' > INT_MAX % 10))) || (sign == -1 && (num > \
					-(INT_MIN / 10) || (num == -(INT_MIN / \
						10) && str[i] - '0' > -(INT_MIN % 10)))))
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	check_int_limits_args(int argc, char **argv)
{
	int	i;

	if (!argv)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_within_int_limits(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_int_limits_string_helper(char *str, int *i)
{
	char	*num_start;
	int		j;
	char	temp;

	num_start = &str[*i];
	j = 0;
	while (str[*i + j] && str[*i + j] != ' ')
		j++;
	temp = str[*i + j];
	str[*i + j] = '\0';
	if (!is_within_int_limits(num_start))
	{
		str[*i + j] = temp;
		return (1);
	}
	str[*i + j] = temp;
	*i += j;
	return (0);
}

int	check_int_limits_string(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			if (check_int_limits_string_helper(str, &i))
				return (0);
	}
	return (1);
}
