/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:03:55 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/07 15:47:24 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_print_address(void *ptr)
{
	unsigned char	address[8];
	int				i;
	char			*buf;

	ft_memcpy((void *)address, (void *)&ptr, 8);
	i = 7;
	while (i >= 0)
	{
		buf = ft_itoa_base((int)address[i], 16);
		if (buf == NULL)
			return ;
		if (ft_strlen(buf) == 1)
			ft_putchar('0');
		ft_putstr(buf);
		free(buf);
		i--;
	}
}

void	ft_print_bytes(void *data, size_t len)
{
	size_t			i;
	char			*buf;
	unsigned char	*bytes;

	if (data == NULL)
		return ;
	bytes = (unsigned char *)data;
	i = 0;
	while (i < len)
	{	
		buf = ft_itoa_base((int)*bytes, 16);
		if (buf == NULL)
			return ;
		ft_print_address(bytes);
		if (ft_strlen(buf) == 1)
			ft_putstr(": 0");
		else
			ft_putstr(": ");
		ft_putstr(buf);
		ft_putchar('\n');
		free(buf);
		bytes++;
		i++;
	}
	ft_putchar('\n');
}
