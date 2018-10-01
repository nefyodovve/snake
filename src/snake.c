#include "snake.h"

t_list *create_snake(int x, int y)
{
	t_list *snake;

	snake = NULL;
	push_front(&snake, x, y);
	return (snake);
}

t_move_res move_snake(t_list **snake, t_cell** field, t_move dir)
{
	int x = (*snake)->x;
	int y = (*snake)->y;
	if (dir == MOVE_UP)
		y--;
	else if (dir == MOVE_DOWN)
		y++;
	else if (dir == MOVE_LEFT)
		x--;
	else if (dir == MOVE_RIGHT)
		x++;
	else if (dir == NOT_MOVE)
		return (NOT_MOVED); 
	if (field[y][x] == EDGE || field[y][x] == BODY)
		return (SMASHED);
	push_front(snake, x, y);
	if (field[y][x] == FOOD) {
		field[y][x] = HEAD;
		return (BON_APPETIT);
	}
	else
		del_back(snake);
	return (MOVE_OK);
}

void destroy_snake(t_list **snake)
{
	clear_list(snake);
}
