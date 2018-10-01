NAME = snake

SRC =	./src/main.c ./src/play.c ./src/display.c ./src/snake.c \
	./src/field.c ./src/list.c
HDR_DIR = ./src
FLAGS = -Wall -Wextra
LIB = ncurses

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I$(HDR_DIR) -o $(NAME) $(SRC) -l$(LIB)

debug: clean
	gcc $(FLAGS) -g -I$(HDR_DIR) -o $(NAME) $(SRC) -l$(LIB)

clean:
	rm -f $(NAME)

re: clean all
