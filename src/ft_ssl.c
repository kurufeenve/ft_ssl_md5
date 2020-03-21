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

#include <stdio.h>
int		main(int argc, char **argv)
{
	//char	buf[512];
	char	usage[] = "usage: ft_ssl command [command opts] [command args]\n";
	//char	*cli_data;
	//char	*cli_buf;
	int		i;
	/*
	 * for testing
	*/
	unsigned char	hash[16];
	unsigned char	hash2[32];
	unsigned char	data[] = {0x34, 0x32};

	argv = NULL;

	i = 1;
	if (argc == 1)
	{
		ft_putstr(usage);
		return (0);
	}
	//char	str[] = "";
	ft_MD5(data, 2, hash);
	printf("data = %s\n", data);
	//ft_putstr("should be:\nd41d8cd98f00b204e9800998ecf8427e\n");
	ft_putstr("hash: ");
	ft_print_bytes(hash, 16);
	ft_sha256(data, 2, hash2);
	system("leaks ft_ssl");
	return (0);
}
