#include "applepie.h"

void interpret(complex* registers, char const* code)
{
	double r;
	double i;

	for (*code; code += 3;)
	{
		complex* dest = &registers[code[2] - '65'];
		complex* src = &registers[code[1] - '65'];

		switch (*code)
		{
			case '=':
				dest->r = src->r;
				dest->i = src->i;
				break;
			case '+':
				dest->r += src->r;
				dest->i += src->i;
				break;
			case '*':
				r = dest->r * src->r - dest->i * src->i;
				i = dest->r * src->i + dest->i * src->r;
				dest->r = r;
				dest->i = i;
				break;
			default:
				fprintf(stderr, "undefined instructions %s {%x}\n", code, *code);
				exit(1);
		}
	}
}