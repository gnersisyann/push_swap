/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:44:16 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/10 17:43:05 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	char		buf[BUFSIZE + 1];
	char		*op_arr;
	char		*op_arr_orig;

	if (argc < 1)
		err();
	if (argc == 1)
		return (0);
	op_arr = ft_strdup("");
	op_arr_orig = op_arr;
	init_checker(&ps, argc, argv);
	fill_op(buf, &op_arr, &op_arr_orig);
	checker_sort(&ps, op_arr);
	free(op_arr_orig);
	free(op_arr);
	if (is_sorted(&ps))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	cleanup(&ps);
}
