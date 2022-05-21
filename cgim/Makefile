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

all: $(EXES)
clean :
	rm -rf $(SRCS_DIR)*.out
	rm -rf $(SRCS_DIR)*.dSYM
fclean :
	rm -rf $(SRCS_DIR)*.out
	rm -rf $(SRCS_DIR)*.dSYM
re :
	make fclean
	make all
%.out : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) $< -o $@
.PHONY : all bonus clean fclean re
