# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 14:43:06 by mgourlai          #+#    #+#              #
#    Updated: 2023/04/17 16:10:45 by mgourlai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_isalnum.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_strchr.c \
	ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
	ft_toupper.c ft_memmove.c ft_strdup.c ft_substr.c ft_strtrim.c\
	ft_strmapi.c ft_strlcpy.c ft_strlcat.c ft_strjoin.c\
	ft_striteri.c ft_substr.c ft_putstr_fd.c ft_putendl_fd.c\
	ft_putchar_fd.c ft_memchr.c ft_itoa.c ft_split.c ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)

SRCSBONUS =	ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstlast.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstsize.c\
		ft_lstadd_back.c\
		ft_lstmap.c

BONUS_OBJS = $(SRCSBONUS:.c=.o)

CC =	gcc
CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

bonus:		$(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:	all clean fclean re
