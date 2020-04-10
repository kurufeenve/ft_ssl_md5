#include "../includes/msg_prep.h"
#include <stdio.h>
void	padding(unsigned char *block, const void *data, unsigned long len, t_padding *p)
{
	unsigned long	pad_len;
	//unsigned long	msg_len_bits;
	//unsigned char	block_size;

	if (block == NULL || data == NULL)
		return ;
	//block_size = block[0];
	//ft_bzero((void *)block, block_size);
	pad_len = p->block_size - sizeof(p->msg_len_bits) - len;
	ft_memcpy((void *)block, data, len);
	block[len] = 0x80;
	//msg_len_bits = len * 8;
	ft_memcpy((void *)&block[p->block_size - sizeof(p->msg_len_bits)],
			(void *)&p->msg_len_bits, sizeof(p->msg_len_bits));
}

void	data_split(unsigned char *block, const void *data, unsigned long len, 
		void *context)
{
	t_padding	p;

	ft_memcpy((void *)&p.offset, context, sizeof(p.offset));
	p.block_size = ((unsigned char *)context)[8];
	p.msg_len_bits = len * 8;
	ft_bzero((void *)block, p.block_size);
	//printf("p.block_size = %u, p.offset = %lu, len = %lu\n", p.block_size, p.offset, len);
	if ((p.block_size + p.offset) < len)
	{
		ft_memcpy((void *)block, &data[p.offset], p.block_size);
		p.offset += p.block_size;
	}
	else
	{
		if (p.msg_len_bits % 512 >= 448 && p.offset < len)
		{
			ft_memcpy((void *)block, &data[p.offset], len - p.offset);
			block[len - p.offset] = 0x80;
			p.offset += p.block_size;
			ft_memcpy(context, (void *)&p.offset, sizeof(p.offset));
			return ;
		}
		else if (p.msg_len_bits % 512 >= 448 && p.offset > len)
		{
			ft_memcpy((void *)&block[56], (void *)&p.msg_len_bits, 8);
			p.offset += p.block_size;
			ft_memcpy(context, (void *)&p.offset, sizeof(p.offset));
			return ;
		}
		else
		{
			padding(block, &data[p.offset], (len - p.offset), &p);
		}
		p.offset = len;
	}
	ft_memcpy(context, (void *)&p.offset, sizeof(p.offset));
}
