#include "snake.h"

t_cell **create_field(int height, int width)
{
	t_cell	**ret;

	ret = (t_cell**)malloc(sizeof(*ret) * height);
	for (int i = 0; i < height; i++)
	{
		ret[i] = (t_cell*)malloc(sizeof(**ret) * width);
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
				ret[i][j] = EDGE;
			else
				ret[i][j] = EMPTY;
		}
	}
	return (ret);
}

void clear_field(t_cell **field, int height, int width) /* from snake, keep borders and food */
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (field[i][j] == FOOD)
				continue;
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1)
				field[i][j] = EDGE;
			else
				field[i][j] = EMPTY;
		}
	}
}

void destroy_field(t_cell **field, int height)
{
	for (int i = 0; i < height; i++)
	{
		free(field[i]);
	}
	free(field);
}

int place_food(t_cell **field, int height, int width, int length)
{
	int free_cells;
	int r;
	int k;

	free_cells = (height - 2) * (width - 2) - length;
	if (free_cells == 0)
		return (1);
	r = rand() % free_cells;
	k = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (field[i][j] == EMPTY && k++ == r)
			{
				field[i][j] = FOOD;
				break;
			}
		}
	}
	return (0);
}

