#ifndef SNAKE_H
# define SNAKE_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ncurses.h>

# define VERSION "0.1"
# define DEFAULT_HEIGHT	20
# define DEFAULT_WIDTH	40
# define DEFAULT_X		10
# define DEFAULT_Y		20

typedef struct	s_settings
{
	int			height;
	int			width;
	int			show_help;
}				t_settings;

typedef enum	e_cell
{
	empty,
	edge,
	head,
	body,
	tail,
	food
}				t_cell;

typedef enum	e_input
{
	none,
	rotate,
	quit
}				t_input;

t_settings		*parse_args(int argc, char **argv);
void			play(t_settings *settings);
void			print_version(void);
void			printw_help(void);
void			printw_field(t_cell **field, t_settings *settings);
void			print_description(void);
t_cell			**create_field(t_settings *settings);
void			destroy_field(t_cell **field, t_settings *settings);
char			*get_str_field(t_cell **field, t_settings *settings);
char			get_field_char(t_cell cell);

#endif
