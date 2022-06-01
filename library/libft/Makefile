NAME := libft.a
SRCS := ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
BONUS_SRCS := ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c
CC := gcc
CFLAGS := -Wall -Wextra -Werror
AR := ar
ARFLAGS := -rc
OBJS := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)
ifdef BONUS
	TOTAL_OBJS = $(OBJS) $(BONUS_OBJS)
else
	TOTAL_OBJS = $(OBJS)
endif
all: $(NAME)
bonus :
	@make BONUS=1
clean :
	rm -rf $(OBJS) $(BONUS_OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
$(NAME) : $(TOTAL_OBJS)
	$(AR) $(ARFLAGS) $@ $?
%.o : %.c
	$(CC) $(CFLAGS) -c $<
