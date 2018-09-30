#ifndef SNAKE_H
# define SNAKE_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ncurses.h>

# define VERSION		"0.1"
# define DEFAULT_HEIGHT	20
# define DEFAULT_WIDTH	40
# define DEFAULT_X		20
# define DEFAULT_Y		10

typedef enum e_cell
{
	EMPTY,
	EDGE,
	BODY,
	HEAD,
	FOOD
} t_cell;

typedef enum e_input
{
	NONE,
	ROTATE,
	PAUSE,
	QUIT,
	GAMEOVER
} t_input;

typedef struct s_snake_list
{
	struct s_snake_list	 *next;
	t_cell				**field;
	int					  x;
	int					  y;
	t_cell				  *cell;
	int					  length;

} t_snake_list;

void			  parse_args(int argc, char **argv, int *height, int *width);
void			  play(int height, int width);
void			  print_version(void);
void			  print_description(void);
void			  show_field(t_cell **field, int height, int width, int pause);
t_cell			**create_field(int height, int width);
void			  destroy_field(t_cell **field, int height);
t_snake_list	 *create_snake(t_cell **field, int x, int y);
t_cell			  move_snake(t_snake_list **snake, int dir);
void			  change_xy(t_snake_list *snake, int dir);
void			  destroy_snake(t_snake_list **snake);
t_input			  handle_input(t_snake_list **snake, int *dir);
void			  destroy_field(t_cell **field, int height);
char			  get_field_char(t_cell cell);
void	place_food(t_snake_list *snake);
int is_opposite_dir(int key1, int key2);

#endif
