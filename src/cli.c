/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:57:57 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/02 17:32:00 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cli.h"
#include <stdio.h>

void	cli(t_ssl *ssl)
{
	int				n;
	size_t			data_len;
	unsigned char	buf[65];
	unsigned char	*data;

	//n = 1;
	data = NULL;
	data_len = 0;
	ft_bzero(buf, 65);
	while((n = read(0, buf, 64)) > 0)
	{
		if (ssl->flags[P] == 1)
			ft_putstr((const char *)buf);
		data = ft_memjoin(data, buf, data_len, n);
		data_len += n;
		ft_bzero(buf, 65);
	}
	ssl->init[ssl->command](ssl->context[ssl->command]);
	ssl->update[ssl->command](ssl->context[ssl->command], (const void *)data, data_len);
	ssl->final[ssl->command](ssl->hash, ssl->context[ssl->command]);
	free(data);
}
