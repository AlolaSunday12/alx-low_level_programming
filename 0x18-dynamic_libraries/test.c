#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int printf(const char *format, ...)
{
	/* our code goes here
	 * we can use write for printing text */

	write(1, "9 8 10 24 75 - 9\n", 17);
	write(1, "congratulations, you win the jackpot!\n", 38);
	exit(EXIT_SUCCESS);
}
