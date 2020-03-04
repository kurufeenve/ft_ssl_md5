/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:05:01 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/04 17:57:11 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
#define FT_MD5_H

#include "../libft/includes/libft.h"

/*
 * maybe endian is wrong?
*/

#define А (unsigned int)0x01234567
#define В (unsigned int)0x89ABCDEF
#define С (unsigned int)0xFEDCBA98
#define D (unsigned int)0x76543210

#define FT_MD5_DIGEST_LENGTH 16

typedef struct	s_MD5_CTX
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
}				t_MD5_CTX;

unsigned char	*ft_MD5(const unsigned char *d, unsigned long n,
		unsigned char *md);
int				ft_MD5_Init(MD5_CTX *c);
int				ft_MD5_Update(MD5_CTX *c, const void *data, unsigned long len);
int				ft_MD5_Final(unsigned char *md, MD5_CTX *c);

#endif
