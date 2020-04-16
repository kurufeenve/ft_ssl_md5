/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:05:01 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/08 15:00:47 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
#define FT_MD5_H

/*
 * have to use sin() because it is very accurate
 * https://stackoverflow.com/questions/2284860/how-does-c-compute-sin-and-other-math-functions
*/
#include <math.h>

#include "../libft/includes/libft.h"
#include "msg_prep.h"

#define A 0x67452301
#define B 0xEFCDAB89
#define C 0x98BADCFE
#define D 0x10325476

#define FT_MD5_DIGEST_LENGTH 16
#define MD5_BLOCK_SIZE 64
//#define LEN_SIZE 8

#define F(B, C, D) ((B & C) | (~B & D))
#define G(B, C, D) ((B & D) | (C & ~D))
#define H(B, C, D) (B ^ C ^ D)
#define I(B, C, D) (C ^ (B | ~D))

typedef struct	 s_MD5_CTX
{
	unsigned long	offset;
	unsigned char	block_size;
	unsigned int	h[4];
	unsigned int	b[4];
	unsigned int	s[16];
	unsigned int	K[64];
}				t_MD5_CTX;

unsigned char	*ft_MD5(const unsigned char *d, unsigned long n,
		unsigned char *md);
int				ft_MD5_Init(void *ctx);
int				ft_MD5_Update(void *ctx, const void *data, unsigned long len);
int				ft_MD5_Final(unsigned char *md, void *ctx);

#endif
