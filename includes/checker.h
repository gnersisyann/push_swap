/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:44:06 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/08 16:42:27 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "stack.h"

void	init_checker(t_push_swap *ps, int argc, char **argv);
void	checker_sort(t_push_swap *ps, char *op_arr);
void	fill_op(char buf[BUFSIZE + 1], char **op_arr, char **op_arr_orig);
void	err(void);
#endif