#include <time.h>
#include <stdio.h>
#include "snake.h"

int main(int argc, char **argv)
{
	int height;
	int width;

	height = DEF_HEIGHT;
	width = DEF_WIDTH;
	if (argc >= 2) {
		width = atoi(argv[1]);
		height = atoi(argv[2]);
	}
	if (height <= 4 || width <= 4)
		return (0);
	play(height, width);
	return (0);
}
