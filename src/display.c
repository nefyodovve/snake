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

void	printw_field(t_cell **field, t_settings *settings)
{
	move(0, 0);
	printw("%s", get_str_field(field, settings));
	if (settings->show_help)
		printw_help();
	else
		printw("\n");
}

char	*get_str_field(t_cell **field, t_settings *settings)
{
	char	*ret;
	int		k;
	int		xmax;
	int		ymax;

	xmax = settings->width;
	ymax = settings->height;
	ret = (char*)malloc(sizeof(*ret) * (ymax * (xmax + 1) + 1));
	k = 0;
	for (int i = 0; i < ymax; i++)
	{
		for (int j = 0; j < xmax; j++)
			ret[k++] = get_field_char(field[i][j]);
		ret[k++] = '\n';
	}
	
	ret[++k] = '\0';
	return (ret);
}

void	printw_help(void)
{
	printw("[arrows] to move; [q] for quit; ");
	printw("[p] for pause; [h] to hide/show this help\n");
}

char	get_field_char(t_cell cell)
{
	switch (cell)
	{
	case empty:
		return (' ');
	case edge:
		return ('#');
	case head:
		return ('0');
	case body:
	case tail:
		return ('o');
	case food:
		return ('@');
	}
	return ('?');
}
