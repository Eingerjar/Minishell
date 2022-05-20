MAKE = make
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
SRCS_DIR = ./srcs/
READLINE_DIR := /goinfre/haryu/.brew/opt/readline/include
READLINE_LIB := /goinfre/haryu/.brew/opt/readline/lib
# READLINE_DIR := /opt/homebrew/opt/readline/include
# READLINE_LIB := /opt/homebrew/opt/readline/lib

SRCS := $(wildcard $(SRCS_DIR)*.c)
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
	$(CC) $(CFLAGS) -I $(READLINE_DIR) -L $(READLINE_LIB) -lreadline -lcurses $< -o $@
.PHONY : all bonus clean fclean re
