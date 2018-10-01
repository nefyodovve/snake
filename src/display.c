#include "snake.h"

void show_field(t_cell **field, int height, int width,
				   t_list *snake)
{	
	clear_field(field, height, width);
	place_snake_to_field(snake, field);
	move(0, 0);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			addch(get_field_char(field[i][j]));
		addch('\n');
	}
}

void show_status(int gameover_flag, int length, int wait_time)
{
	printw("[q] for quit; [p] of [space] for pause\n");
	printw("arrows or [wasd] for moving\n");
	printw("Length:\t%d\n", length);
	printw("Delay:\t%d ms\n", wait_time);
	if (gameover_flag == 1)
		printw("[GAME OVER]\n");
	if (gameover_flag == 2)
		printw("[THAT'S PLAYING TO WIN, BABY]\n");
}

char get_field_char(t_cell cell)
{
	switch (cell)
	{
	case EMPTY:
		return (' ');
	case EDGE:
		return ('#');
	case HEAD:
		return ('0');
	case BODY:
		return ('o');
	case FOOD:
		return ('@');
	}
	return ('?');
}

void place_snake_to_field(t_list *snake, t_cell **field)
{
	if (snake)
	{
		field[snake->y][snake->x] = HEAD;
		snake = snake->next;
		while (snake)
		{
			field[snake->y][snake->x] = BODY;
			snake = snake->next;
		}
	}
}
