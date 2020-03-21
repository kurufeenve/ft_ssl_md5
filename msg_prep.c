#include "includes/msg_prep.h"

void	padding(unsigned char *block, const void *data, unsigned long len)
{
	unsigned long	pad_len;
	unsigned long	msg_len_bits;

	ft_bzero((void *)block, BLOCK_SIZE);
	pad_len = BLOCK_SIZE - LEN_SIZE - len;
	ft_memcpy((void *)block, data, len);
	block[len] = 0x80;
	msg_len_bits = len * 8;
	ft_memcpy((void *)(&block[len + pad_len]), (void *)&msg_len_bits, \
			sizeof(msg_len_bits));
}
