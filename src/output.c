#include "../includes/output.h"

void	output(t_ssl *ssl)
{
	ft_print_bytes(ssl->hash, ssl->hash_size);
}
