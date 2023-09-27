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
DEBUG	= -fsanitize=address

SRCS	=	core/main_bonus.c \
		core/pipex_bonus.c \
		core/utils_bonus.c \
		core/utils2_bonus.c \
		core/utils3_bonus.c \
		core/cmdexec_bonus.c \
		core/heredoc_bonus.c \
	
OBJS	= $(SRCS:.c=.o)
	
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(DEBUG) -o $(NAME) -lreadline
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY:all, clean, fclean, re
