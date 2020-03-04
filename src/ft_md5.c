/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:24:07 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/04 18:09:45 by vordynsk         ###   ########.fr       */
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
	ft_MD5_Update(&c, d, n);
	/*
	 * while(still have some data)
	 * md5_update()
	 */
	ft_MD5_Final(md, &c);
	ft_memset(&c, 0, sizeof(c));
}

int				ft_MD5_Init(MD5_CTX *c)
{
	ft_memset(c, 0, sizeof(*c));
	c->a = A;
	c->b = B;
	c->c = C;
	c->d = D;
	return (1);
}

int				ft_MD5_Update(MD5_CTX *c, const void *data, unsigned long len)
{

}
