#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

//------ERROR------//
void	ft_error(char *msg);

//------VALIDATION------//
int		validate_input(int argc, char **argv);
int		is_number(char *str);
int		has_duplicates(int *nums, int count);
int		check_all_numbers(int argc, char **argv);
int		check_duplicates_args(int argc, char **argv);
int		is_valid_quoted_numbers(char *str);
int		count_numbers_in_string(char *str);
int		*extract_numbers_from_string(char *str, int *count);

//------LIMITS VALIDATION------//
int		is_within_int_limits(char *str);
int		check_int_limits_args(int argc, char **argv);
int		check_int_limits_string(char *str);

#endif