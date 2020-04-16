/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:35:00 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/07 13:59:30 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

void	init(t_ssl *ssl)
{
	ssl->init[MD5] = ft_MD5_Init;
	ssl->init[SHA256] = ft_SHA256_Init;
	ssl->update[MD5] = ft_MD5_Update;
	ssl->update[SHA256] = ft_SHA256_Update;
	ssl->final[MD5] = ft_MD5_Final;
	ssl->final[SHA256] = ft_SHA256_Final;
}
#include <stdio.h>
int		main(int argc, char **argv)
{
	char			usage[] = "usage: ft_ssl command [command opts] [command args]\n";
	t_ssl			ssl;
	t_MD5_CTX		m;
	t_SHA256_CTX	s;
	/*
	 * for testing
	*/
	unsigned char	hash[16];
	unsigned char	hash2[32];
	unsigned char	data[] = {0x34, 0x32};

	if (argc == 1)
	{
		ft_putstr(usage);
		return (0);
	}
	ft_bzero((void *)&ssl, sizeof(ssl));
	ssl.ac = argc;
	ssl.av = argv;
	init(&ssl);
	ssl.context[MD5] = (void *)&m;
	ssl.context[SHA256] = (void *)&s;
	router(&ssl);
	ft_print_bytes((void *)ssl.flags, 4);
	output(&ssl);
	//cli();

	ft_MD5(data, 2, hash);
	ft_putstr("md5 hash: ");
	ft_print_bytes(hash, 16);
	ft_sha256(data, 2, hash2);
	ft_putstr("SHA256 (\"");
	ft_putstr((char *)data);
	ft_putstr("\") = ");
	ft_print_bytes(hash2, 32);
	ft_sha256((unsigned char *)g_sample_text, ft_strlen(g_sample_text), hash2);
	ft_putstr("SHA256 (g_sample_text) = ");
	ft_print_bytes(hash2, 32);
	system("leaks ft_ssl");
	return (0);
}
