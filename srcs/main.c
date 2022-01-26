#include "../includes/fractol.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (INVALID_ARGUMENT);
	new_window(argc, argv);
	return (0);
}