#include "snake.h"

void	play(t_settings *settings)
{
	t_cell	**field;
	t_info	info;
	t_input input_res;

	initscr(); // Initializate ncurses
	cbreak(); // C-z and C-c works
	noecho(); // Do not echo when getchar()
	keypad(stdscr, TRUE); // enable function keys (such as arrows)
	field = create_field(settings);
	printw_field(field, settings);
	refresh();
	while (1)
	{
		input_res = handle_input(field, settings, &info);
		if (input_res == quit)
			break;
		printw_field(field, settings);
		refresh();
	}
	destroy_field(field, settings);
	endwin(); // Quit ncurses and restore shell
}

t_input	handle_input(t_cell **field, t_settings *settings, t_info *info)
{
	int	c;

	c = getch();
	switch (c)
	{
	case 'q':
		return (quit);
	case 'h':
		settings->show_help ^= 1; // swap 0 and 1
		break;
	case KEY_DOWN:
	case KEY_UP:
	case KEY_LEFT:
	case KEY_RIGHT:
	}
	return (none);
}

t_cell	**create_field(t_settings *settings)
{
	t_cell	**ret;
	int		xmax;
	int		ymax;

	xmax = settings->width;
	ymax = settings->height;
	ret = (t_cell**)malloc(sizeof(*ret) * ymax);
	for (int i = 0; i < ymax; i++)
	{
		ret[i] = (t_cell*)malloc(sizeof(**ret) * xmax);
		for (int j = 0; j < xmax; j++)
		{
			ret[i][j] = (i == 0 || j == 0 || i == ymax - 1 || j == xmax - 1
						 ? edge : empty);
		}
	}
	ret[DEFAULT_Y][DEFAULT_X] = head;
	return (ret);
}

void	destroy_field(t_cell **field, t_settings *settings)
{
	for (int i = 0; i < settings->height; i++)
	{
		free(field[i]);
	}
	free(field);
}
