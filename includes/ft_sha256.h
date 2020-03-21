#ifndef FT_SHA256_H
#define FT_SHA256_H

#include "../libft/includes/libft.h"

#define H0 0x6a09e667
#define H1 0xbb67ae85
#define H2 0x3c6ef372
#define H3 0xa54ff53a
#define H4 0x510e527f
#define H5 0x9b05688c
#define H6 0x1f83d9ab
#define H7 0x5be0cd19

typedef struct		s_SHA256_CTX
{
	unsigned int	*K;
}					t_SHA256_CTX;

unsigned char *ft_sha256(const unsigned char *d, unsigned long n,
		unsigned char *hash);
int				ft_SHA256_Init(t_SHA256_CTX *c);
int				ft_SHA256_Update(t_SHA256_CTX *c, const void *data,
		unsigned long len);
int				ft_SHA256_Final(unsigned char *md, t_SHA256_CTX *c);

#endif
