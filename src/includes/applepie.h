#include <stdio.h>
#include <stdlib.h>

#ifndef APPLE_PIE_H
# define APPLE_PIE_H

# define sqr(x) ((x) * (x))

typedef struct
{
	double r;
	double i;
}	complex;

void	interpret(complex* registers, char const* code);
int		main(int argc, char **argv);

#endif