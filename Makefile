# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 18:36:54 by haryu             #+#    #+#              #
#    Updated: 2022/06/04 17:46:15 by cgim             ###   ########.fr        #
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
READLINE_INCLUDE_DIR 		= ${addprefix $(INCLUDES_DIR), readline/}
READLINE_LIB_DIR 			= ${addprefix $(LIB_DIR), readline/}

all							: $(NAME)

clean 						: 
								$(MAKE) clean -C $(LIBFT_DIR)
								rm -rf $(SRCS_DIR)*.o
						   		rm -rf $(SRCS_DIR)*.dSYM
fclean 						:
	 							$(MAKE) fclean -C $(LIBFT_DIR)
								rm -rf $(SRCS_DIR)*.o
								rm -rf $(SRCS_DIR)*.dSYM
								rm -rf $(NAME)
re 							:
								make fclean
								make all
debug 						:
								make all CFLAGS+="-Wall -Werror -Wextra -g3 -fsanitize=address"

%.o:%.c
							$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -I $(READLINE_INCLUDE_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(NAME) 					: $(OBJS)
								$(MAKE) bonus -C $(LIBFT_DIR)
								$(CC) $(CFLAGS) -L$(READLINE_LIB_DIR) -I$(INCLUDES_DIR) -I$(READLINE_INCLUDE_DIR) -I$(LIBFT_DIR) $(LIBFTA) -lreadline $^ -o $@

.PHONY : all bonus clean fclean re debug

