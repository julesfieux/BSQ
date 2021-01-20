# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfieux <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 14:51:27 by jfieux            #+#    #+#              #
#    Updated: 2020/09/30 16:28:41 by jfieux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= BSQ

SRC			=	main.c \
				parsing.c \
				tool_box.c \
				display.c \
				ft_find.c

OBJ			= $(SRC:.c=.o)
INCLD		= -I.

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
DEBUG		= -fsanitize=address -g3
RM			= /bin/rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(INCLD)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
			$(RM) $(OBJ)

debug:		$(OBJ)
			$(CC) $(CFLAGS) $(DEBUG) -o $(NAME) $(OBJ)

fclean:		clean
			$(RM) $(NAME) $(NAME).dSYM

re:			fclean all

.PHONY:		all clean debug fclean re
