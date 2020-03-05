/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:24:07 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/05 18:36:56 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_md5.h"

unsigned char *ft_MD5(const unsigned char *d, unsigned long n,
		unsigned char *md)
{
	t_MD5_CTX				c;
	static unsigned char	m[FT_MD5_DIGEST_LENGTH];

	if (md == NULL)
	{
		md = m;
	}
	ft_MD5_Init(&c);
	ft_MD5_Update(&c, d, n);
	/*
	 * while(still have some data)
	 * md5_update()
	 */

	ft_MD5_Final(md, &c);
	ft_memset(&c, 0, sizeof(c));
	return (md);
}

int				ft_MD5_Init(t_MD5_CTX *c)
{
	ft_memset(c, 0, sizeof(*c));
	c->a = A;
	c->b = B;
	c->c = C;
	c->d = D;
	return (1);
}

void			padding(unsigned char *block)

int				ft_MD5_Update(t_MD5_CTX *c, const void *data, unsigned long len)
{
	len = 0;
	if (c->a > 0)
	{}
	return (1);
}

int				ft_MD5_Final(unsigned char *md, t_MD5_CTX *c)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		ft_memcpy(&md[i], (unsigned char *)(&c[i]), 4);
		i += 4;
	}
	return (1);
}
