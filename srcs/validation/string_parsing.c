/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:22 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:46:23 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	count_numbers_in_string(char *str)
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
		{
			in_number = 0;
		}
		i++;
	}
	return (count);
}

static void	extract_numbers_from_string_helper(char *tmp_ptr, int num_count,
		int **nums)
{
	char	*start;
	char	temp;
	int		i;
	int		j;

	i = 0;
	while (i < num_count)
	{
		while (*tmp_ptr == ' ')
			tmp_ptr++;
		start = tmp_ptr;
		j = 0;
		while (tmp_ptr[j] && tmp_ptr[j] != ' ')
			j++;
		temp = tmp_ptr[j];
		tmp_ptr[j] = '\0';
		(*nums)[i] = ft_atoi(start);
		tmp_ptr[j] = temp;
		tmp_ptr += j;
		i++;
	}
}

int	*extract_numbers_from_string(char *str, int *count)
{
	int		*nums;
	int		num_count;
	char	*tmp;
	char	*tmp_ptr;

	num_count = count_numbers_in_string(str);
	*count = num_count;
	if (num_count == 0)
		return (NULL);
	nums = malloc(sizeof(int) * num_count);
	if (!nums)
		return (NULL);
	tmp = ft_strdup(str);
	if (!tmp)
	{
		free(nums);
		return (NULL);
	}
	tmp_ptr = tmp;
	extract_numbers_from_string_helper(tmp_ptr, num_count, &nums);
	free(tmp);
	return (nums);
}
