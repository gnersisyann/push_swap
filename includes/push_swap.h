/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:59:50 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/08 14:56:49 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include "stack.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFSIZE 4096

typedef enum e_locations
{
	TOP_A,
	BOTTOM_A,
	TOP_B,
	BOTTOM_B
}				t_locations;

typedef struct s_chunk
{
	t_locations	loc;
	int			size;
}				t_chunk;

typedef struct s_split
{
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
}				t_split;

//------ERROR------//
void			ft_error(char *msg);

//------VALIDATION------//
int				validate_input(int argc, char **argv);
int				is_number(char *str);
int				has_duplicates(int *nums, int count);
int				check_all_numbers(int argc, char **argv);
int				check_duplicates_args(int argc, char **argv);
int				is_valid_quoted_numbers(char *str);
int				count_numbers_in_string(char *str);
int				*extract_numbers_from_string(char *str, int *count);

//------LIMITS VALIDATION------//
int				is_within_int_limits(char *str);
int				check_int_limits_args(int argc, char **argv);
int				check_int_limits_string(char *str);

//------SORT------//
void			sort(t_push_swap *data);
int				is_sorted(t_push_swap *data);

//------DEFAULT SORTS------//
void			sort_3(t_push_swap *ps);
void			sort_5(t_push_swap *ps);

//------CHUNK SORT------//
void			chunk_sort(t_push_swap *data);
void			chunk_split(t_push_swap *data, t_chunk *to_split,
					t_split *dest);
void			recursive_chunk_sort(t_push_swap *data, t_chunk *to_sort);
void			chunk_to_the_top(t_push_swap *data, t_chunk *to_sort);
int				chunk_value(t_push_swap *data, t_chunk *chunk, int n);
int				chunk_max_value(t_push_swap *data, t_chunk *chunk);

void			sort_three(t_push_swap *data, t_chunk *to_sort);
void			sort_three_top_a(t_push_swap *data, t_chunk *to_sort,
					t_stack *stk, int max);
void			sort_three_top_b(t_push_swap *data, t_chunk *to_sort,
					t_stack *stk, int max);
void			sort_three_bottom_a(t_push_swap *data, t_chunk *to_sort,
					t_stack *stk, int max);
void			sort_three_bottom_b(t_push_swap *data, t_chunk *to_sort,
					t_stack *stk, int max);
void			sort_two(t_push_swap *data, t_chunk *to_sort);
void			sort_one(t_push_swap *data, t_chunk *to_sort);

t_stack			*loc_to_stack(t_push_swap *data, t_locations loc);
void			innit_size(t_chunk *min, t_chunk *mid, t_chunk *max);
void			set_split_loc(t_locations loc, t_chunk *min, t_chunk *mid,
					t_chunk *max);
void			set_third_pivots(t_locations loc, int crt_size, int *pivot_1,
					int *pivot_2);

int				move_from_to(t_push_swap *data, t_locations from,
					t_locations to);
void			move_from_top_a(t_push_swap *data, t_locations to);
void			move_from_top_b(t_push_swap *data, t_locations to);
void			move_from_bottom_a(t_push_swap *data, t_locations to);
void			move_from_bottom_b(t_push_swap *data, t_locations to);
#endif