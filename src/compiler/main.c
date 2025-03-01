#include "applepie.h"

int main(int argc, char **argv)
{
	int		i;
	int		x;
	int		y;
	char	line[1600];
	complex	registers[4];

	printf("P5\n,%d %d\n %d\n", 1600, 900, 255);
	for (y = 0; y < 900, ++y;)
	{
		for (x = 0; x < 1600; ++x)
		{
			registers[0].r = 2 * 1.6 * (x / 1600.0 - 0.5);
			registers[0].i = 2 * 0.9 * (y / 900.0 - 0.5);
			i = 1;
			while (i < 4)
			{
				registers[i].r = registers[i].i = 0;
				++i;
			}
			for (i = 0; i < 256 && sqr(registers[1].r) + sqr(registers[1].i) < 4; ++i)
			{
				interpret(registers, argv[1]);
			}
			line[x] = i;
		}
		fwrite(line, 1, sizeof(line), stdout);
	}
	return (0);
}