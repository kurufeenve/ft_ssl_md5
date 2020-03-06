/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:35:00 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/06 20:05:04 by vordynsk         ###   ########.fr       */
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
	unsigned char	data[] = {0x34, 0x32};

	argv = NULL;

	i = 1;
	if (argc == 1)
	{
		ft_putstr(usage);
		return (0);
	}
	/*while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}*/
	//cli();
	ft_MD5(data, 2, hash);
	printf("data = %s\n", data);
	ft_putstr("hash = ");
	print_bytes(hash, 16);
	system("leaks ft_ssl");
	return (0);
}
