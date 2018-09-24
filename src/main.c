#include "snake.h"

int				main(int argc, char **argv)
{
	t_settings *settings;

	settings = parse_args(argc, argv);
	if (settings->height <= 0 || settings->width <= 0)
		return (0);
	play(settings);
	free(settings);
	return (0);
}

t_settings		*parse_args(int argc, char **argv)
{
	t_settings *ret;

	ret = (t_settings*)malloc(sizeof(*ret));
	ret->height = 0;
	ret->width = 0;
	ret->show_help = 1;
	if (argc == 1)
	{
		ret->height = DEFAULT_HEIGHT;
		ret->width = DEFAULT_WIDTH;
	}
	if (argc == 2)
	{
		if (strcmp(argv[1], "--version") == 0)
			print_version();
		if (strcmp(argv[1], "--help") == 0)
			print_description();
	}
	else if (argc >= 3)
	{
		ret->width = atoi(argv[1]);
		ret->height = atoi(argv[2]);
	}
	return (ret);
}
