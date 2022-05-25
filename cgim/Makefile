MAKE = make
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
SRCS_DIR = ./srcs/
SRCS := $(wildcard $(SRCS_DIR)*.c)
INCLUDES_DIR = ./includes/
EXES := $(SRCS:.c=.out)
#OBJS := $(SRCS:.c=.o)
LIBFT_DIR = ./libft/
LIBFT_AFILE = libft.a
LIBFTA = ${addprefix $(LIBFT_DIR), $(LIBFT_AFILE)}
READLINE_INCLUDE_DIR = ./readline_includes/
READLINE_LIB_DIR = ./readline_lib/

all: $(EXES)
clean :
	make clean -C $(LIBFT_DIR)
	rm -rf $(SRCS_DIR)*.out
	rm -rf $(SRCS_DIR)*.dSYM
fclean :
	make fclean -C $(LIBFT_DIR)
	rm -rf $(SRCS_DIR)*.out
	rm -rf $(SRCS_DIR)*.dSYM
re :
	make fclean
	make all
%.out : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -I $(READLINE_INCLUDE_DIR) -L $(READLINE_LIB_DIR) -I $(LIBFT_DIR) -lreadline $(LIBFTA) $< -o $@
.PHONY : all bonus clean fclean re
