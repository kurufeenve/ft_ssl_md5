#ifndef OUTPUT_H
#define OUTPUT_H

#include "../libft/includes/libft.h"
#include "ft_ssl_data_types.h"

typedef struct	s_out
{
	char		out_string[64];
}				t_out;

void	output(t_ssl *ssl);

#endif
