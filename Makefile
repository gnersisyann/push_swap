CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror #-fsanitize=address
RM					=	rm -f

NAME				=	ps
PUSH_SWAP			=	push_swap
CHECKER				=	checker

LIBFT				=	libft.a
LIBFT_NAME			=	ft
LIBFT_DIR			=	libs/libft
LIBFT_FILE			=	$(LIBFT_DIR)/$(LIBFT)
CFLAGS				+=	-I$(LIBFT_DIR)/include -Iincludes
LDFLAGS				=	-L$(LIBFT_DIR) -l$(LIBFT_NAME)
MAKE_LIB			=	make -C

STACK_SRC_DIR		=	srcs/stack
PUSH_SWAP_SRC_DIR	=	srcs/push_swap
VALIDATION_SRC_DIR	=	srcs/validation
CHECKER_SRC_DIR		=	srcs/checker

STACK_INC			=	includes/stack.h
PUSH_SWAP_INC		=	$(STACK_INC) includes/push_swap.h
CHECKER_INC			=	$(STACK_INC) $(PUSH_SWAP_INC) includes/checker.h

STACK_SRC			=	$(STACK_SRC_DIR)/stack_init.c \
						$(STACK_SRC_DIR)/stack_init_helper.c \
						$(STACK_SRC_DIR)/stack_utils.c \
						$(STACK_SRC_DIR)/operations/op_optimize.c \
						$(STACK_SRC_DIR)/operations/op_utils.c \
						$(STACK_SRC_DIR)/operations/push.c \
						$(STACK_SRC_DIR)/operations/swap.c \
						$(STACK_SRC_DIR)/operations/rotate.c \
						$(STACK_SRC_DIR)/operations/r_rotate.c 

VALIDATION_SRC		=	$(VALIDATION_SRC_DIR)/validation_main.c \
						$(VALIDATION_SRC_DIR)/validation_numbers.c \
						$(VALIDATION_SRC_DIR)/validation_duplicates.c \
						$(VALIDATION_SRC_DIR)/string_parsing.c \
						$(VALIDATION_SRC_DIR)/validation_quoted.c \
						$(VALIDATION_SRC_DIR)/validation_limits.c \
						$(VALIDATION_SRC_DIR)/error_handling.c

PS_SRC				=	$(PUSH_SWAP_SRC_DIR)/default_sorts.c \
						$(PUSH_SWAP_SRC_DIR)/main_sorts.c \
						$(PUSH_SWAP_SRC_DIR)/chunk_sort.c \
						$(PUSH_SWAP_SRC_DIR)/chunk_sort_utils.c \
						$(PUSH_SWAP_SRC_DIR)/chunk_sort_three.c \
						$(PUSH_SWAP_SRC_DIR)/chunk_sort_utils2.c \
						$(PUSH_SWAP_SRC_DIR)/chunk_operations.c \
						$(PUSH_SWAP_SRC_DIR)/move.c \

CHECKER_SRC			=	$(CHECKER_SRC_DIR)/checker_main.c \
						$(CHECKER_SRC_DIR)/checker_utils.c

CHECKER_FULL_SRC	=	$(STACK_SRC) \
						$(VALIDATION_SRC) \
						$(PS_SRC) \
						$(CHECKER_SRC)

PUSH_SWAP_SRC		=	$(PUSH_SWAP_SRC_DIR)/main.c \
						$(STACK_SRC) \
						$(VALIDATION_SRC) \
						$(PS_SRC) \

OBJ_DIR				=	obj
PUSH_SWAP_OBJ		=	$(PUSH_SWAP_SRC:%.c=$(OBJ_DIR)/%.o)
CHECKER_OBJ			=	$(CHECKER_FULL_SRC:%.c=$(OBJ_DIR)/%.o)

all:					$(NAME) bonus

$(NAME):				$(PUSH_SWAP)

bonus:					$(CHECKER)

$(OBJ_DIR)/%.o:			%.c
						@mkdir -p $(dir $@)
						$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_FILE):
						$(MAKE_LIB) $(LIBFT_DIR)

$(PUSH_SWAP):			$(LIBFT_FILE) $(PUSH_SWAP_OBJ)
						$(CC) $(CFLAGS) $(PUSH_SWAP_OBJ) $(LDFLAGS) -o $@

$(CHECKER):				$(LIBFT_FILE) $(CHECKER_OBJ)
						$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LDFLAGS) -o $@

clean:
						$(MAKE_LIB) $(LIBFT_DIR) clean
						rm -rf $(OBJ_DIR)

fclean:					clean
						$(MAKE_LIB) $(LIBFT_DIR) fclean
						$(RM) $(PUSH_SWAP) $(CHECKER)

re:						fclean all

.PHONY:					all clean fclean re bonus
