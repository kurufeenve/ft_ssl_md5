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
	ft_memcpy((void *)ssl->usage, (void *)"usage: ft_ssl command [command opts] [command args]\n", 52);
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
	t_ssl			ssl;
	t_MD5_CTX		m;
	t_SHA256_CTX	s;

	ft_bzero((void *)&ssl, sizeof(ssl));
	ssl.ac = argc;
	ssl.av = argv;
	init(&ssl);
	if (ssl.ac == 1)
	{
		ft_putstr(ssl.usage);
		system("leaks ft_ssl");
		return (0);
	}
	ssl.context[MD5] = (void *)&m;
	ssl.context[SHA256] = (void *)&s;
	
	router(&ssl);
	output(&ssl);

	system("leaks ft_ssl");
	return (0);
}
