#include "../includes/ft_sha256.h"
#include <stdio.h>
unsigned char *ft_sha256(const unsigned char *d, unsigned long n,
		unsigned char *hash)
{
	t_SHA256_CTX	c;
	static unsigned char	h[FT_SHA256_DIGEST_LEN];

	if (hash == NULL)
	{
		hash = h;
	}
	ft_bzero((void *)hash, FT_SHA256_DIGEST_LEN);
	ft_SHA256_Init(&c);
	ft_SHA256_Update(&c, d, n);
	ft_SHA256_Final(hash, &c);
	return (hash);
}

void			init_hash(t_SHA256_CTX *c)
{
	c->block_size = SHA256_BLOCK_SIZE;
	c->H[0] += H0;
	c->H[1] += H1;
	c->H[2] += H2;
	c->H[3] += H3;
	c->H[4] += H4;
	c->H[5] += H5;
	c->H[6] += H6;
	c->H[7] += H7;
}

int				ft_SHA256_Init(t_SHA256_CTX *c)
{
	unsigned int	*tmp;

	ft_bzero(c, sizeof(*c));
	init_hash(c);
	tmp = (unsigned int []){
0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};
	ft_memcpy(c->K, tmp, 64 * 4);
	return (1);
}

static void			pre_calc(t_SHA256_CTX *c, unsigned int current_block)
{
	int		i;

	ft_bzero((void *)c->w, sizeof(*c->w) * SHA256_BLOCK_SIZE);
	ft_memcpy(c->w, c->block, 64);
	if (c->num_of_blocks - current_block == 1)
		ft_endian_swap((void *)&c->w[14], 8);
	i = 0;
	while (i < 16)
	{
		ft_endian_swap((void *)&c->w[i], 4);
		i++;
	}
	while (i < SHA256_BLOCK_SIZE)
	{
		c->s0 = S_I(c->w[i - 15], 7, 18, 3);
		c->s1 = S_I(c->w[i - 2], 17, 19, 10);
		c->w[i] = c->w[i - 16] + c->s0 + c->w[i - 7] + c->s1;
		i++;
	}
	ft_memcpy((void *)c->b, (void *)c->H, 32);
}

static void			calc_block(t_SHA256_CTX *c)
{
		int		i;

		i = 0;
		while (i < SHA256_BLOCK_SIZE)
		{
			c->s1 = S_II(c->H[4], 6, 11, 25);
			c->ch = CH(c->H[4], c->H[5], c->H[6]);
			c->tmp1 = c->H[7] + c->s1 + c->ch + c->K[i] + c->w[i];
			c->s0 = S_II(c->H[0], 2, 13, 22);
			c->maj = MAJ(c->H[0], c->H[1], c->H[2]);
			c->tmp2 = c->s0 + c->maj;
			c->H[7] = c->H[6];
			c->H[6] = c->H[5];
			c->H[5] = c->H[4];
			c->H[4] = c->H[3] + c->tmp1;
			c->H[3] = c->H[2];
			c->H[2] = c->H[1];
			c->H[1] = c->H[0];
			c->H[0] = c->tmp1 + c->tmp2;
			i++;
		}
}

int				ft_SHA256_Update(t_SHA256_CTX *c, const void *data,
		unsigned long len)
{
	int				i;
	unsigned int	j;

	c->num_of_blocks = len * 8 / 512;
	if (len * 8 % 512 > 0)
		c->num_of_blocks++;
	if (len * 8 % 512 >= 448)
		c->num_of_blocks++;
	j = 0;
	while (j < c->num_of_blocks)
	{
		data_split(c->block, data, len, (void *)c);
		pre_calc(c, j);
		calc_block(c);
		i = 0;
		while (i < 8)
		{
			c->H[i] += c->b[i];
			i++;
		}
		j++;
	}
	return (1);
}

int				ft_SHA256_Final(unsigned char *hash, t_SHA256_CTX *c)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		ft_endian_swap((void *)&c->H[i], 4);
		i++;
	}
	ft_memcpy((void *)hash, (void *)c->H, FT_SHA256_DIGEST_LEN);
	return (1);
}
