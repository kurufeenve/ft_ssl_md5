#include "../includes/options.h"

void	options(t_ssl *ssl)
{
	if (ssl->ac > 2 && ssl->av[OPTIONS][0] == '-')
	{
		ft_putstr("OPTION!\n");
	}
}
