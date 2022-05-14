# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 23:43:42 by haryu             #+#    #+#              #
#    Updated: 2022/05/14 11:46:11 by haryu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR 			= .
SRCS				= $(wildcard $(SRCS_DIR)*.c)
EXES				= $(SRCS:.c=.out)

CC					= gcc

sky					:=$(shell tput setaf 6)
reset				:=$(shell tput sgr0)

all					:$(EXES)
					$(info $(sky)========== all ===========$(reset))

%.out				:%.c
					$(info $(sky)========== $(<) $(@) ==========$(reset))
					$(CC) -lreadline -L/opt/homebrew/Cellar/readline/8.1.2/lib -I/opt/homebrew/Cellar/readline/8.1.2/include/library -lcurses $< -c -o $@ 

clean				:
					$(info $(sky)========== clean ==========$(reset))
					$(RM) *.out

fclean				: clean
					$(info $(sky)========== fclean ==========$(reset))
					$(RM) *.out

re					:fclean all
					$(info $(shell tput setiaf 1)========== re ==========$(reset))

.PHONY				: all clean fclean re bonus 
