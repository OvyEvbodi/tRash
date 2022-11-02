#include "main.h"

int main(int argc __attribute__((unused)), char **argv)
{
	int i = 0;

	while (argv[i])
	{
		printf("the arg at pos %d is -> %s\n", i+1, argv[i]);
		i++;
	}
	return (0);
}
