#include <stdio.h>
#include <string.h>

int		main(void)
{
	unsigned int	*s;
	s = (unsigned int []){7, 12, 17,
						22, 5,  9, 
						14, 20, 4, 
						11, 16, 23, 
						6, 10, 15, 
						21};
	const char		str[] = "1st part "
							"second part";
	printf("%s\n", str);
	for (int i = 0; i < 16; i++)
	{
		printf("%u ", s[i]);
	}
	return (0);
}
