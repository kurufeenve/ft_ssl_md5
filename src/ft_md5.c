/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:24:07 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/08 13:55:21 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_md5.h"

#include <stdio.h>
unsigned char *ft_MD5(const unsigned char *d, unsigned long n,
		unsigned char *md)
{
	t_MD5_CTX				c;
	static unsigned char	m[FT_MD5_DIGEST_LENGTH];

	if (md == NULL)
	{
		md = m;
	}
	ft_bzero((void *)md, FT_MD5_DIGEST_LENGTH);
	ft_MD5_Init(&c);
	ft_MD5_Update(&c, d, n);
	ft_MD5_Final(md, &c);
	ft_memset(&c, 0, sizeof(c));
	return (md);
}

int				ft_MD5_Init(void *ctx)
{
	unsigned int	i;
	unsigned int	s[] = {7, 12, 17, 22, 5,  9, 14, 20, 4, 11, 16, 23, 6, 10, 15, 21};
	t_MD5_CTX		*c;

	c = (t_MD5_CTX *)ctx;
	ft_bzero(c, sizeof(*c));
	c->block_size = MD5_BLOCK_SIZE;
	c->h[0] = A;
	c->h[1] = B;
	c->h[2] = C;
	c->h[3] = D;
	ft_memcpy(c->s, s, sizeof(c->s));
	i = 0; 
	while (i < 64)
	{
		c->K[i] = (unsigned int)(0x100000000 * fabs(sin(i + 1)));
		i++;
	}
	return (1);
}

int				ft_MD5_Update(void *ctx, const void *data, unsigned long len)
{
	unsigned int	block[MD5_BLOCK_SIZE / 4];
	unsigned int	F;
	unsigned int	g;
	size_t			i;
	unsigned int	j;
	unsigned int	num_of_blocks;
	t_MD5_CTX		*c;

	c = (t_MD5_CTX *)ctx;

	num_of_blocks = len * 8 / 512;
	if (len * 8 % 512 > 0)
	{
		num_of_blocks++;
	}
	if (len * 8 % 512 >= 448)
	{
		num_of_blocks++;
	}
	j = 0;
	while (j < num_of_blocks)
	{
		ft_memcpy((void *)c->b, (void *)c->h, 16);
		data_split((unsigned char *)block, data, len, (void *)c);
		ft_print_bytes((void *)block, 64);
		i = 0;
		while (i < 64)
		{
			if (i < 16)
			{
				F = F(c->h[1], c->h[2], c->h[3]);
				g = i;
			}
			else if (i > 15 && i < 32)
			{
				F = G(c->h[1], c->h[2], c->h[3]);
				g = (5 * i + 1) % 16;
			}
			else if (i > 31 && i < 48)
			{
				F = H(c->h[1], c->h[2], c->h[3]);
				g = (3 * i + 5) % 16;
			}
			else if (i > 47 && i < 64)
			{
				F = I(c->h[1], c->h[2], c->h[3]);
				g = (7 * i) % 16;
			}
			F = F + c->h[0] + c->K[i] + block[g];
			c->h[0] = c->h[3];
			c->h[3] = c->h[2];
			c->h[2] = c->h[1];
			c->h[1] = c->h[1] + RoL(F, c->s[((int)(i / 16) * 4 + (i % 4))]);
			i++;
		}
		c->h[0] += c->b[0];
		c->h[1] += c->b[1];
		c->h[2] += c->b[2];
		c->h[3] += c->b[3];
		j++;
	}
	/*c->h[0] += A;
	c->h[1] += B;
	c->h[2] += C;
	c->h[3] += D;*/
	return (1);
}

int				ft_MD5_Final(unsigned char *md, void *ctx)
{
	t_MD5_CTX		*c;

	c = (t_MD5_CTX *)ctx;
	ft_memcpy(md, (unsigned char *)c->h, 16);
	return (1);
}
