#include "snake.h"

int main(int argc, char **argv)
{
	int height;
	int width;

	height = 0;
	width = 0;
	parse_args(argc, argv, &height, &width);
	if (height <= 0 || width <= 0)
		return (0);
	play(height, width);
	return (0);
}

void parse_args(int argc, char **argv, int *height, int *width)
{
	*height = 0;
	*width = 0;
	if (argc == 1) {
		*height = DEFAULT_HEIGHT;
		*width = DEFAULT_WIDTH;
	}
	if (argc >= 2 && atoi(argv[1]) == 0)
	{
		if (strcmp(argv[1], "--version") == 0)
			print_version();
		if (strcmp(argv[1], "--help") == 0)
			print_description();
	}
	else if (argc >= 3)
	{
		*width = atoi(argv[1]);
		*height = atoi(argv[2]);
	}
}
