CFLAGS := -Wall -W -Iinclude

SRC = ./src/main.c \
	  ./src/socket.c \
	  ./src/data.c

OBJ = $(SRC:.c=.o)

NAME = calc_serv

all: $(OBJ)
	cc $(OBJ) -o $(NAME)
	
$(NAME): all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re