#ifndef MSG_PREP_H
#define MSG_PREP_H

#include "../libft/includes/libft.h"
#include "ft_md5.h"
#include "ft_sha256.h"

typedef struct		s_padding
{
	unsigned long	msg_len_bits;
	unsigned long	last_block_padding_len;
	unsigned char	block_size;
	unsigned long	offset;
}					t_padding;

void	padding(unsigned char *block, const void *data, unsigned long len);
void	data_split(unsigned char *block, const void *data, unsigned long len, 
		void *context);

#endif
