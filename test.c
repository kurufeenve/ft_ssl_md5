#include <stdio.h>
#include <string.h>

typedef struct __attribute__((packed))	s_TEST
{
	long		fuck_you;
	char		a;
	int			b;
	long		c;
	long		d;
	unsigned int	s[16];
}				t_TEST;

int		main(void)
{
	t_TEST	T;
	unsigned int s[16] = {7, 12, 17, 22, 5,  9, 14, 20, 4, 11, 16, 23, 6, 10, 15, 21};
	memcpy((void *)T.s, s, 16);
	printf("sizeof T = %zu", sizeof(T));
	return (0);
}
