#include "snake.h"


t_snake_list *create_snake_part(void)
{
	t_snake_list *part;

	part = (t_snake_list*)malloc(sizeof(*part));
	if (part) {
		part->next = NULL;
	}
	return (part);
}

t_snake_list *copy_snake_part(t_snake_list *source)
{
	t_snake_list *part;

	part = create_snake_part();
	part->field = source->field;
	part->x = source->x;
	part->y = source->y;
	part->length = source->length;
	return (part);
}

t_snake_list *create_snake(t_cell **field, int x, int y)
{
	t_snake_list *head;
	head = create_snake_part();
	head->field = field;
	head->x = x;
	head->y = y;
	field[y][x] = HEAD;
	head->length = 1;
	return (head);
}

t_cell move_snake(t_snake_list **snake, int key_dir)
{
	t_snake_list *head;
	t_snake_list *p;
	/* t_cell new_cell; */

	head = copy_snake_part(*snake); /* Create copy of head */
	change_xy(head, key_dir);			/* Move it to given direction */
	head->next = *snake;			/* Link new head with previous head */
	(*snake)->field[(*snake)->y][(*snake)->x] = BODY; /* Set previous head to BODY */
	*snake = head;					/* Change initial snake head poiter */
	p = *snake;						/* Counter variable */
	if (p->length > 1)
		while (p->next->next)	/* Stop on pre-last part of snake */
			p = p->next;
	if (head->field[head->y][head->x] == FOOD) { /* If food, don't delete last part */
		(*snake)->length += 1;
		head->field[head->y][head->x] = HEAD;
		return (FOOD);
	}
	else if (head->field[head->y][head->x] == EDGE)	
		return (EDGE); 			/* Return if slams into edge... */
	else if (head->field[head->y][head->x] == BODY) 
		return (BODY);			/* ...or itself */
	else {						/* Delete last part */
		p->next->field[p->next->y][p->next->x] = EMPTY;
		free(p->next);
		p->next = NULL;
	}
	head->field[head->y][head->x] = HEAD;
	return (EMPTY);
}

void change_xy(t_snake_list *snake, int key_dir)
{
	switch (key_dir)
	{
	case KEY_UP:
		snake->y -= 1;
		break;
	case KEY_DOWN:
		snake->y += 1;
		break;
	case KEY_LEFT:
		snake->x -= 1;
		break;
	case KEY_RIGHT:
		snake->x += 1;
		break;
	}
}

/*

oo0
ooo0
 oo0

*/
