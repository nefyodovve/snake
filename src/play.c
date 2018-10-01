#include "snake.h"
#include <time.h>

void	play(int height, int width)
{
	t_cell **field = create_field(height, width);
	t_list *snake = create_snake(width / 2, height / 2);
	t_input input;
	t_input prev_input;
	int pause_flag = 0;
	int gameover_flag = 0;
	int length = 1;
	t_move_res move_res = 0;
	int wait_time;
	int clock_start;
	int clock_end;

	initscr();					/* Initializate ncurses */
	cbreak();					/* C-z and C-c works */
	noecho();					/* Do not echo when getchar() */
	keypad(stdscr, TRUE);		/* enable function keys (such as arrows) */
	nodelay(stdscr, 1);			/* getch() will not wait */

	srand(time(NULL));
	place_food(field, height, width, length);
	length = 1;
	prev_input = INPUT_UP;
	wait_time = DEF_DELAY;
	show_field(field, height, width, snake);
	show_status(gameover_flag, length, wait_time);
	clock_start = clock();
	while (1) {
		input = handle_input();
		if (input == INPUT_QUIT)
			break;
		if (input == INPUT_PAUSE)
		{
			clock_start = clock(); /* to have wait_time after pause ends */
			pause_flag ^= 1;	/* swap 0 and 1*/
		}
		if (!pause_flag && !gameover_flag)
		{
			if (is_input_move(input)) {
				move_res = move_snake(
					&snake, field, input_to_move(input, prev_input, length));
				if (move_res != NOT_MOVED) /* fix pseudo-pause when trying to move opposite */
					clock_start = clock(); /* don't mess user input with automove */
			}
			clock_end = clock();
			if ((clock_end - clock_start) * 1000 / CLOCKS_PER_SEC >= wait_time) {
				clock_start = clock();
				move_res = move_snake(&snake, field, prev_input); /* automove */
			}
			if (move_res == BON_APPETIT)
			{
				length++;
				move_res = MOVE_OK; /* do not eat prev. food on next iteration */
				if (place_food(field, height, width, length) == 1)
					gameover_flag = 2; /* win */
				wait_time *= 0.97;
				if (wait_time < MIN_DELAY) /* we don't want to play with 20 ms delay */
					wait_time = MIN_DELAY;
			}
			else if (move_res == SMASHED)
				gameover_flag = 1; /* lose */
			if (is_input_move(input))
				if (move_res != NOT_MOVED) /* don't update prev_input if user tryed opposite dir */
					prev_input = input;

			show_field(field, height, width, snake); /* display all */
			show_status(gameover_flag, length, wait_time);
		}
	}
	destroy_field(field, height);
	destroy_snake(&snake);

	endwin(); /* Quit ncurses and restore shell */
}

t_input handle_input(void)
{
	int key;

	key = getch();
	switch (key)
	{
	case (KEY_UP):
	case ('w'):
		return (INPUT_UP);
	case (KEY_DOWN):
	case ('s'):
		return (INPUT_DOWN);
	case (KEY_LEFT):
	case ('a'):
		return (INPUT_LEFT);
	case (KEY_RIGHT):
	case ('d'):
		return (INPUT_RIGHT);
	case ('p'):
	case (' '):
		return (INPUT_PAUSE);
	case ('q'):
		return (INPUT_QUIT);
	}
	return (INPUT_NONE);
}

int is_input_move(t_input input)
{
	if (input == INPUT_UP || input == INPUT_DOWN)
		return (1);
	if (input == INPUT_LEFT || input == INPUT_RIGHT)
		return (1);
	return (0);
}

t_move input_to_move(t_input input, t_input prev_input, int length)
{
	if (length == 1)
		return ((t_move)input);
	else {
		if (prev_input == INPUT_LEFT && input == INPUT_RIGHT)
			return (NOT_MOVE);
		if (prev_input == INPUT_RIGHT && input == INPUT_LEFT)
			return (NOT_MOVE);
		if (prev_input == INPUT_UP && input == INPUT_DOWN)
			return (NOT_MOVE);
		if (prev_input == INPUT_DOWN && input == INPUT_UP)
			return (NOT_MOVE);
	}
	return ((t_move)input);
}
