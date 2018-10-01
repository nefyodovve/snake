NAME = snake

SRC =	./src/main.c ./src/play.c ./src/display.c ./src/snake.c \
	./src/field.c ./src/list.c
INCLUDE = ./src
CC = gcc
CFLAGS = -Wall -Wextra
LIB = ncurses


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $(NAME) $(SRC) -l$(LIB)

debug: clean
	$(CC) $(CFLAGS) -g -I$(INCLUDE) -o $(NAME) $(SRC) -l$(LIB)

clean:
	@rm -f $(NAME)
	@rm -f $(NAME).exe

re: clean all
