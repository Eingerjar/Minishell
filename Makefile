# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 18:36:54 by haryu             #+#    #+#              #
#    Updated: 2022/07/02 01:27:43 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 						= minishell
MAKE	 					= make
CC 							= gcc
CFLAGS 						= -Wall -Werror -Wextra
SRCS_DIR 					= ./src/
SRCS 						:= $(wildcard $(SRCS_DIR)*.c)
INCLUDES_DIR 				= ./includes/
LIB_DIR 					= ./library/
OBJS 						:= $(SRCS:.c=.o)
LIBFT_DIR 					= ${addprefix $(LIB_DIR), libft/}
LIBFT_AFILE 				= libft.a
LIBFTA 						= ${addprefix $(LIBFT_DIR), $(LIBFT_AFILE)}
READLINE_INCLUDE_DIR 		= ${addprefix $(INCLUDES_DIR), readline}
sky							:=$(shell tput setaf 6)
reset						:=$(shell tput sgr0)


all							: $(NAME)

clean 						: 
							$(MAKE) clean -C $(LIBFT_DIR)
							@rm -rf $(SRCS_DIR)*.o
						   	@rm -rf $(SRCS_DIR)*.dSYM
							@rm -rf ./temp
							$(info $(shell tput setaf 1)============= $(NAME) clean =============$(reset))

fclean 						:
	 						$(MAKE) fclean -C $(LIBFT_DIR)
							@rm -rf $(SRCS_DIR)*.o
							@rm -rf $(SRCS_DIR)*.dSYM
							@rm -rf $(NAME)
							@rm -rf ./temp
							$(info $(shell tput setaf 1)============= $(NAME) fclean =============$(reset))

re 							:
							make fclean
							make all
							$(info $(shell tput setaf 1)============= $(NAME) recompile =============$(reset))

debug 						:
							make all CFLAGS+="-Wall -Werror -Wextra -g3 -fsanitize=address"

%.o							:%.c
							$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -I $(READLINE_INCLUDE_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(NAME) 					: $(OBJS)
								$(info $(shell tput setaf 1)============= $(NAME) =============$(reset))
								$(MAKE) bonus -C $(LIBFT_DIR)
								$(info $(sky)============= libft.a =============$(reset))
								$(CC) $(CFLAGS) $(LDFLAGS) -I$(INCLUDES_DIR) -I$(READLINE_INCLUDE_DIR) -I$(LIBFT_DIR) $(LIBFTA) -lreadline $^ -o $@
								$(info $(shell tput setaf 1)============= $(NAME) =============$(reset))
								@sh makefolder.sh

.PHONY : all bonus clean fclean re debug
