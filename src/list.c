#include "snake.h"

t_list *create_elem(int x, int y)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(*new));
	if (new) {
		new->x = x;
		new->y = y;
		new->next = NULL;
	}
	return (new);
}

int push_front(t_list **list, int x, int y)
{
	t_list *new;
	if (*list == NULL) {
		*list = create_elem(x, y);
		if (!(*list))
			return (1);
	}
	else {
		new = create_elem(x, y);
		if (!new)
			return (1);
		new->next = *list;
		*list = new;
	}
	return (0);
}

void del_back(t_list **list)
{
	t_list *iter;
	if (*list) {
		if ((*list)->next == NULL) {
			free(*list);
			*list = NULL;
		}
		else {
			iter = *list;
			while (iter->next->next)
				iter = iter->next;
			free(iter->next);
			iter->next = NULL;
		}
	}
}

void clear_list(t_list **list)
{
	t_list *temp;
	t_list *iter;

	if (*list) {
		iter = *list;
		while (iter) {
			temp = iter->next;
			free(iter);
			iter = temp;
		}
	}
}
