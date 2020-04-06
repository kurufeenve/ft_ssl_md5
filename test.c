#include <stdio.h>
#include <string.h>

int		main(void)
{
	int num = 1;

	if (*(char *)&num == 1)
	{
		printf("Little-Endian\n");
	}
	else
	{
		printf("Big-Endian\n");
	}
	return (0);
}
