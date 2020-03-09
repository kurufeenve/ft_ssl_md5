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
void	print_bytes(unsigned char *bytes, size_t len);
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

	ft_bzero(c, sizeof(*c));
	c->a = A;
	c->b = B;
	c->c = C;
	c->d = D;
	i = 0; 
	while (i < 64)
	{
		c->K[i] = floor(0xFFFFFFFF * fabs(sin(i + 1)) + 1);
		i++;
	}
	unsigned char	*s_c = (unsigned char *)c;
	i = 0;
	while (i < sizeof(*c))
	{
		ft_print_bytes(s_c, 4);
		i += 4;
		s_c += 4;
	}
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
	unsigned char	block[BLOCK_SIZE];

	//ft_bzero(block, BLOCK_SIZE);
	padding(block, data, len);

	len = 0;
	data = NULL;
	if (c->a > 0)
	{}
	return (1);
}

int				ft_MD5_Final(unsigned char *md, t_MD5_CTX *c)
{
	ft_memcpy(md, (unsigned char *)c, 16);
	return (1);
}
