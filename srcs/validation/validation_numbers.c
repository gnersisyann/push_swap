/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:16 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:59:21 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_number(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_all_numbers(int argc, char **argv)
{
	int	i;

	if (!argv || argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
