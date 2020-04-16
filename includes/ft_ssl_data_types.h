#ifndef FT_SSL_DATA_TYPES
#define FT_SSL_DATA_TYPES

//#include "ft_md5.h"
//#include "ft_sha256.h"

#define COMMAND 1
#define OPTIONS 2

enum				flags
{
	P,
	Q,
	R,
	S
};

enum				commands
{
	MD5,
	SHA256
};

typedef	int (*Init)(void *ctx);
typedef	int (*Update)(void *ctx, const void *data, unsigned long len);
typedef	int (*Final)(unsigned char *hash, void *ctx);

typedef struct		s_ssl
{
	int				ac;
	char			**av;
	unsigned char	command;
	unsigned char	flags[4];
	unsigned char	data[64];
	Init			init[2];
	Update			update[2];
	Final			final[2];
	void			*context[2];
	unsigned int	hash_size;
	unsigned char	hash[32];
}					t_ssl;

#endif
