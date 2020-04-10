#ifndef FT_SHA256_H
#define FT_SHA256_H

#include "../libft/includes/libft.h"
#include "msg_prep.h"

#define H0 0x6a09e667
#define H1 0xbb67ae85
#define H2 0x3c6ef372
#define H3 0xa54ff53a
#define H4 0x510e527f
#define H5 0x9b05688c
#define H6 0x1f83d9ab
#define H7 0x5be0cd19

#define FT_SHA256_DIGEST_LEN 32
#define SHA256_BLOCK_SIZE 64

#define CH(B, C, D) ((B & C) | (~B & D))
#define S_I(x, a, b, c) (RoR(x, a) ^ RoR(x, b) ^ (x >> c))
#define S_II(x, a, b, c) (RoR(x, a) ^ RoR(x, b) ^ RoR(x, c))
#define MAJ(a, b, c) ((a & b) ^ (a & c) ^ (b & c))

typedef struct		s_SHA256_CTX
{
	unsigned long	offset;
	unsigned char	block_size;
	unsigned int	H[8];
	unsigned int	b[8];
	unsigned int	num_of_blocks;
	unsigned char	block[SHA256_BLOCK_SIZE];
	unsigned int	K[SHA256_BLOCK_SIZE];
	unsigned int	w[SHA256_BLOCK_SIZE];
	unsigned int	s0;
	unsigned int	s1;
	unsigned int	ch;
	unsigned int	tmp1;
	unsigned int	tmp2;
	unsigned int	maj;
}					t_SHA256_CTX;

unsigned char *ft_sha256(const unsigned char *d, unsigned long n,
		unsigned char *hash);
int				ft_SHA256_Init(t_SHA256_CTX *c);
int				ft_SHA256_Update(t_SHA256_CTX *c, const void *data,
		unsigned long len);
int				ft_SHA256_Final(unsigned char *hash, t_SHA256_CTX *c);

#endif
