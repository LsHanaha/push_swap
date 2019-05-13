#
#	Compiler variables
#

CC= gcc
CC_FLAGS= -Wall -Wextra -Werror
NAME_PS = push_swap
NAME_CH = checker
LIB_DIR = libft/includes
HEADERDIR = ../
SRC = ft_ps_quicksort.c ft_ps_quicksort_help.c ft_ps_funcs1.c ft_ps_funcs2.c ft_ps_helpers.c ft_ps_helpers2.c ft_ps_other.c\
 ft_ps_stack_ins.c ft_ps_stack_ins2.c push_swap_sorts.c ft_ps_helpers3.c ft_quick_without_swap.c ft_check_values.c
PS_SRC = push_swap.c
CH_SRC = checker.c
OBJ= $(SRC:.c=.o)
LIB=libft/libft.a


#
#	Debug mode settings
#

#debug: CC_FLAGS += $(DG_CC_FLAGS)
#debug: $(NAME)

#
#	Release mode
#

all: $(NAME_PS)

$(NAME_PS): $(OBJ)
	@make -C libft/ debug
	@make -C libft/ clean
	@$(CC) $(PS_SRC) $(CC_FLAGS) $(OBJ) $(LIB) -I $(LIB_DIR) -o $(NAME_PS)
	@$(CC) $(CH_SRC) $(CC_FLAGS) $(OBJ) $(LIB) -I $(LIB_DIR) -o $(NAME_CH)


%.o : %.c
	@$(CC)  $(FLAGS) -I $(LIB_DIR) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME_PS)
	rm -rf $(NAME_CH)

re: fclean all
