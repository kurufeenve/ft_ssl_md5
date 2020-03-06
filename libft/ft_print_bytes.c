/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bytes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:03:55 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/06 20:04:53 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	print_bytes(unsigned char *bytes, size_t len)
{
	size_t	i;
	char	*buf;

	i = 0;
	while (i < len)
	{
		buf = ft_itoa_base((int)bytes[i], 16);
		if (buf == NULL)
			return ;
		if (ft_strlen(buf) == 1)
			ft_putchar('0');
		ft_putstr(buf);
		free(buf);
		i++;
	}
	ft_putchar('\n');
}
