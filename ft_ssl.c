/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:35:00 by vordynsk          #+#    #+#             */
/*   Updated: 2020/02/09 16:50:23 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/ft_ssl.h"

int		main(int argc, char **argv)
{
	char	buf;
	char	usage[] = "usage: ft_ssl command [command opts] [command args]\n";
	char	*cli_data;
	char	*cli_buf;
	int		i;

	i = 1;
	if (argc == 1)
	{
		ft_putstr(usage);
		return (0);
	}
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}

	while(read(1, &buf, 1))
	{
		//cli_data = ft_strjoin(cli_data, &buf);
	}
	ft_putstr(cli_data);
	system("leaks ft_ssl");
	return (0);
}
