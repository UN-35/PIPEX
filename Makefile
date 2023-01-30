NAME= pipex

CFLAGS= -Wall -Wextra -Werror 

SRC= ft_split.c ft_strjoin.c ft_strlen.c ft_strncmp.c get_path.c main.c

OBJ= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(OBJ) $(CFLAGS) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all