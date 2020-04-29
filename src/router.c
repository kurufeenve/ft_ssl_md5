#include "../includes/router.h"
#include "../includes/ft_md5.h"
#include <stdio.h>
static void read_file()
{

}

static void read_string(t_ssl *ssl, int	item, size_t offset)
{
	ssl->init[ssl->command](ssl->context[ssl->command]);
	ssl->update[ssl->command](ssl->context[ssl->command],
			(const void *)&ssl->av[item][offset],
			ft_strlen(&ssl->av[item][offset]));
	ssl->final[ssl->command](ssl->hash, ssl->context[ssl->command]);
}

static void	set_flags(t_ssl *ssl, int offset)
{
	size_t	j;

	j = 1;
	while (j < 5 && j < ft_strlen(ssl->av[offset]))
	{
		if (ssl->av[offset][j] == 'p')
		{
			ssl->flags[P] = 1;
			cli(ssl);
		}
		else if (ssl->av[offset][j] == 'q')
			ssl->flags[Q] = 1;
		else if (ssl->av[offset][j] == 'r')
			ssl->flags[R] = 1;
		else if (ssl->av[offset][j] == 's')
		{
			ssl->flags[S] = 1;
			if (j == ft_strlen(ssl->av[offset]) - 1)
			{
				if (offset + 2 > ssl->ac)
				{
					ft_putstr(ssl->usage);
					system("leaks ft_ssl");
					exit(0);
				}
				read_string(ssl, offset + 1, 0);
				break ;
			}
			read_string(ssl, offset, j + 1);
		}
		j++;
	}
}

static void	read_options(t_ssl *ssl)
{
	int		i;
	int		f;

	i = OPTIONS;
	f = 1;
	while(i < ssl->ac)
	{
		if (ssl->av[i][0] == '-' && f == 1)
			set_flags(ssl, i);
		if (ssl->av[i][0] != '-')
			f = 0;
		if (f == 0)
			read_file();
		i++;
	}
}

void		router(t_ssl *ssl)
{
	if (!(ft_strcmp(ssl->av[COMMAND], "md5")))
	{
		ssl->command = MD5;
		ssl->hash_size = 16;
	}
	else if (!(ft_strcmp(ssl->av[COMMAND], "sha256")))
	{
		ssl->command = SHA256;
		ssl->hash_size = 32;
	}
	else
	{
		ft_putstr("ft_ssl: Error: '");
		ft_putstr(ssl->av[COMMAND]);
		ft_putstr("' is an invalid command.\n\nStandard commands:\n\n"
"Message Digest commands:\nmd5\nsha256\n\nCipher commands:\n");
		system("leaks ft_ssl");
		exit(1);
	}
	if (ssl->ac > 2 && ssl->av[OPTIONS][0] == '-')
	{
		read_options(ssl);
	}
	if (((ssl->ac == 3 && ssl->av[OPTIONS][0] == '-') || ssl->ac == 2) && ssl->flags[P] == 0 && ssl->flags[S] == 0)
	{
		cli(ssl);
	}
}
