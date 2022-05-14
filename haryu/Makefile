MAKE = make
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
SRCS_DIR = ./srcs/
READLINE_DIR := /opt/homebrew/Cellar/readline/8.1.2/include
READLINE_LIB := /opt/homebrew/Cellar/readline/8.1.2/lib
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
