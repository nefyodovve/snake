#include "snake.h"

void	print_version(void)
{
	printf("%s\n", VERSION);
}

void	print_description(void)
{
	printf("Just snake game.\n");
	printf("Default settings:\n");
	printf("field width  = %d\n", DEFAULT_WIDTH);
	printf("field height = %d\n", DEFAULT_HEIGHT);
}

void	show_field(t_cell **field, int height, int width, int pause)
{
	move(0, 0);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			addch(get_field_char(field[i][j]));
		addch('\n');
	}
	printw("[q] for quit; [p] for pause");
	if (pause) {
		move(0, width + 1);
		printw("PAUSE");
	}
}

char	get_field_char(t_cell cell)
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
