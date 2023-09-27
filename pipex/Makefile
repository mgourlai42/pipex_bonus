# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgourlai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 15:37:28 by mgourlai          #+#    #+#              #
#    Updated: 2023/08/07 15:37:29 by mgourlai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC	= cc
RM	= rm -rf
CFLAGS	= -Wall -Wextra -Werror
DEBUG	= -g3 -fsanitize=address

SRCS	=	core/main.c \
		core/pipex.c \
		core/utils.c \
		core/utils2.c \
	
OBJS	= $(SRCS:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(DEBUG) -o $(NAME)  

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY:all, clean, fclean, re
