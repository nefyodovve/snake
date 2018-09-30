#include "snake.h"

void	play(int height, int width)
{
	/* t_info			  info; */
	t_input			  input_res;
	t_cell			**field;
	t_snake_list	 *snake;
	int				  pause;
	int				  dir;

	initscr(); /* Initializate ncurses */
	cbreak(); /* C-z and C-c works */
	noecho(); /* Do not echo when getchar() */
	keypad(stdscr, TRUE); /* enable function keys (such as arrows) */
	
	field = create_field(height, width);
	field[8][8] = FOOD;
	field[7][2] = FOOD;
	field[9][1] = FOOD;
	field[9][1] = FOOD;
	snake = create_snake(field, DEFAULT_X, DEFAULT_Y);
	dir = KEY_LEFT;
	pause = 0;

	show_field(field, height, width, pause);
	refresh();
	while (1) {
		input_res = handle_input(&snake, &dir);
		if (input_res == QUIT)
			break;
		if (input_res == GAMEOVER)
		{
			break;
			// todo
		}
		if (input_res == PAUSE) {
			pause = -pause;
		}
		if (pause)				
			continue;
		/* move_snake(&snake, dir); */
		/* sleep function */
		show_field(field, height, width, pause);
		refresh();
	}
	if (input_res == GAMEOVER)
	{
		printw("\n\nGAMEOVER");
		while (getch() != 'q');
	}
	destroy_field(field, height);
	/* destroy_snake() */
	endwin(); /* Quit ncurses and restore shell */
}

t_input	handle_input(t_snake_list **snake, int *key)
{
	int	prev_key;
	t_cell new_cell;

	prev_key = *key;
	*key = getch();
	new_cell = 0;
	switch (*key)
	{
	case 'q':
		return (QUIT);
	case 'p':
		return (PAUSE);
	case KEY_DOWN:
	case KEY_UP:
	case KEY_LEFT:
	case KEY_RIGHT:
		if ((*snake)->length == 1)
			new_cell = move_snake(snake, *key); /* THIS SHIT NOT WORKS BLYAT */
		else if (!is_opposite_dir(prev_key, *key))
			new_cell = move_snake(snake, *key);
		break;
	}
	if (new_cell == EDGE || new_cell == BODY)
		return (GAMEOVER);
	if (new_cell == FOOD) {
		place_food(*snake); 	/* todo */
	}
	return (NONE);
}

t_cell	**create_field(int height, int width)
{
	t_cell	**ret;

	ret = (t_cell**)malloc(sizeof(*ret) * height);
	for (int i = 0; i < height; i++) {
		ret[i] = (t_cell*)malloc(sizeof(**ret) * width);
		for (int j = 0; j < width; j++) {
			ret[i][j] = (i == 0 || j == 0 || i == height - 1 || j == width - 1
						 ? EDGE : EMPTY);
		}
	}
	return (ret);
}

void	destroy_field(t_cell **field, int height)
{
	for (int i = 0; i < height; i++) {
		free(field[i]);
	}
	free(field);
}

void	place_food(t_snake_list *snake)
{
	if (snake)
		return ;
}

int		is_opposite_dir(int key1, int key2)
{
	if (key1 == KEY_UP && key2 == KEY_DOWN)
		return (1);
	if (key1 == KEY_DOWN && key2 == KEY_UP)
		return (1);
	if (key1 == KEY_LEFT && key2 == KEY_RIGHT)
		return (1);
	if (key1 == KEY_RIGHT && key2 == KEY_LEFT)
		return (1);
	return (0);
}
