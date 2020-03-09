#include <stdio.h>

typedef struct __attribute__((packed))	s_TEST
{
	long		fuck_you;
	char		a;
	int			b;
	long		c;
	long		d;
}				t_TEST;

int		main(void)
{
	t_TEST	T;

	printf("sizeof T = %zu", sizeof(T));
	return (0);
}
