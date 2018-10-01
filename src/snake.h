#ifndef SNAKE_H
# define SNAKE_H

# ifdef __unix__
#  include <ncurses.h>
# elif defined(_WIN32) || defined(_WIN64)
#  include <ncurses/ncurses.h>
# endif
# include <stdlib.h>

# define DEF_HEIGHT 10
# define DEF_WIDTH	15
# define DEF_DELAY	1000
# define MIN_DELAY	300

typedef enum	e_cell
{
	EMPTY,
	EDGE,
	BODY,
	HEAD,
	FOOD
} t_cell;

typedef enum e_input {
	INPUT_NONE,
	INPUT_UP,
	INPUT_DOWN,
	INPUT_LEFT,
	INPUT_RIGHT,
	INPUT_PAUSE,
	INPUT_QUIT
} t_input;

typedef enum e_move {
	NOT_MOVE,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT
} t_move;

typedef enum e_move_res {
	MOVE_OK,
	NOT_MOVED,
	SMASHED,
	BON_APPETIT
} t_move_res;

typedef struct s_list
{
	struct s_list *next;
	int x;
	int y;

} t_list;

t_list		 *create_elem(int x, int y);
int			  push_front(t_list **list, int x, int y);
void		  del_back(t_list **list);
void		  clear_list(t_list **list);
void		  play(int height, int width);
t_list		 *create_snake(int x, int y);
t_move_res	  move_snake(t_list **snake, t_cell** field, t_move dir);
void		  destroy_snake(t_list **snake);
t_cell		**create_field(int height, int width);
void		  destroy_field(t_cell **field, int height);
void		  clear_field(t_cell **field, int height, int width);
t_input		  handle_input(void);
int			  is_input_move(t_input input);
t_move		  input_to_move(t_input input, t_input prev_input, int length);
void		  show_field(t_cell **field, int height, int width, t_list *snake);
void		  init_colors(void);
void		  show_status(int gameover_flag, int length, int wait_time);
char		  get_field_char(t_cell cell);
void		  place_snake_to_field(t_list *snake, t_cell **field);
int			  place_food(t_cell **field, int height, int width, int length);

#endif
