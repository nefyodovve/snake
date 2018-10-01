#include "snake.h"

void init_colors(void)
{
	init_pair(1, COLOR_BLACK, COLOR_BLACK); /* EMPTY */
	init_pair(2, COLOR_RED, COLOR_BLACK); /* EDGE */
	init_pair(3, COLOR_WHITE, COLOR_BLACK); /* BODY */
	init_pair(4, COLOR_GREEN, COLOR_BLACK); /* FOOD */
}

int get_pair_num(t_cell cell)
{
	if (cell == EMPTY)
		return (1);
	if (cell == EDGE)
		return (2);
	if (cell == BODY || cell == HEAD)
		return (3);
	if (cell == FOOD)
		return (4);
	return (0);
}

void show_color(t_cell **field, int height, int width)
{
	char c;
	int p;
	int i, j;

	move(0, 0);
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			c = get_field_char(field[i][j]);
			p = get_pair_num(field[i][j]);
			attron(COLOR_PAIR(p));
			addch(c);
			attroff(COLOR_PAIR(p));
		}
		addch('\n');
	}
}

void show_field(t_cell **field, int height, int width, t_list *snake)
{
	int i;
	int j;

	clear_field(field, height, width);
	place_snake_to_field(snake, field);
	if (has_colors())
		show_color(field, height, width);
	else {
		move(0, 0);
		for (i = 0; i < height; i++) {
			for (j = 0; j < width; j++)
				addch(get_field_char(field[i][j]));
			addch('\n');
		}
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
	if (snake) {
		field[snake->y][snake->x] = HEAD;
		snake = snake->next;
		while (snake) {
			field[snake->y][snake->x] = BODY;
			snake = snake->next;
		}
	}
}
