MAKE = make
CC = gcc
CFLAGS = -Wall -Werror -Wextra
READLINE_DIR := $(HOME)/.brew/opt/readline/include
READLINE_LIB := $(HOME)/.brew/opt/readline/lib
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
fclean :
	rm -rf $(SRCS_DIR)*.out
re :
	make fclean
	make all
%.out : %.c
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -I$(READLINE_DIR) -L$(READLINE_LIB) -lreadline -lcurses $< -o $@
.PHONY : all bonus clean fclean re
