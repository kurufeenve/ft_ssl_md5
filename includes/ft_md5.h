/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:05:01 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/06 17:12:45 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
#define FT_MD5_H

#include "../libft/includes/libft.h"

/*
 * maybe endian is wrong?
*/

#define A 0x67452301
#define B 0xEFCDAB89
#define C 0x98BADCFE
#define D 0x10325476

#define FT_MD5_DIGEST_LENGTH 16
#define BLOCK_SIZE 64
#define LEN_SIZE 8

typedef struct	s_MD5_CTX
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
}				t_MD5_CTX;

unsigned char	*ft_MD5(const unsigned char *d, unsigned long n,
		unsigned char *md);
int				ft_MD5_Init(t_MD5_CTX *c);
int				ft_MD5_Update(t_MD5_CTX *c, const void *data, unsigned long len);
int				ft_MD5_Final(unsigned char *md, t_MD5_CTX *c);

#endif
