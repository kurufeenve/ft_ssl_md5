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

int				ft_MD5_Init(t_MD5_CTX *c)
{
	unsigned int	i;
	unsigned int	s[] = {7, 12, 17, 22, 5,  9, 14, 20, 4, 11, 16, 23, 6, 10, 15, 21};

	ft_bzero(c, sizeof(*c));
	c->a = A;
	c->b = B;
	c->c = C;
	c->d = D;
	ft_memcpy(c->s, s, sizeof(c->s));
	//ft_print_bytes(c->s, sizeof(c->s));
	i = 0; 
	while (i < 64)
	{
		c->K[i] = floor(0xFFFFFFFF * fabs(sin(i + 1)) + 1);
		i++;
	}
	/*unsigned char	*s_c = (unsigned char *)c;
	i = 0;
	printf("c->K[0] = %X\n", c->K[0]);
	while (i < sizeof(*c))
	{
		printf("%08x\n", *((unsigned int *)s_c));
		i += 4;
		s_c += 4;
	}*/
	return (1);
}

static void		padding(unsigned char *block, const void *data, unsigned long len)
{
	unsigned long	pad_len;

	ft_bzero((void *)block, BLOCK_SIZE);
	pad_len = BLOCK_SIZE - LEN_SIZE - len;
	ft_memcpy((void *)block, data, len);
	block[len] = 0x80;
	ft_memcpy((void *)(&block[len + pad_len - 1]), (void *)&len, sizeof(len));
}

int				ft_MD5_Update(t_MD5_CTX *c, const void *data, unsigned long len)
{
	unsigned int	block[BLOCK_SIZE]; // should be unsigned int? and size/4?
	unsigned int	F;
	unsigned int	g;
	size_t			i;

	padding((unsigned char *)block, data, len);
	i = 0;
	while (i < 64)
	{
		if (i < 16)
		{
			F = F(c->b, c->c, c->d);
			g = i;
		}
		else if (i > 15 && i < 32)
		{
			F = G(c->b, c->c, c->d);
			g = (5 * i + 1) % 16;
		}
		else if (i > 31 && i < 48)
		{
			F = H(c->b, c->c, c->d);
			g = (3 * i + 5) % 16;
		}
		else if (i > 47 && i < 64)
		{
			F = I(c->b, c->c, c->d);
			g = (7 * i) % 16;
		}
		F = F + c->a + c->K[i] + block[g];
		c->a = c->d;
		c->d = c->c;
		c->c = c->b;
		c->b = c->b + LEFTROTATE(F, c->s[((int)(i / 16) * 4 + (i % 4))]);
		i++;
	}
	return (1);
}

int				ft_MD5_Final(unsigned char *md, t_MD5_CTX *c)
{
	ft_memcpy(md, (unsigned char *)c, 16);
	return (1);
}
