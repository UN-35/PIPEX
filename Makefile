# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 15:41:29 by yoelansa          #+#    #+#              #
#    Updated: 2023/02/05 15:09:58 by yoelansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex

CFLAGS= -Wall -Wextra -Werror 

SRC= ft_split.c ft_strjoin.c ft_strrchr.c ft_strlen.c ft_strncmp.c get_path.c main.c

OBJ= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(OBJ) $(CFLAGS) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all