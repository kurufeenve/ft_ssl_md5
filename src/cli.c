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

void	cli(void)
{
	char	buf[512];
	int		n;
	char	*cl_input;
	int		cl_input_len;
	
	n = 1;
	cl_input_len = 0;
	cl_input = NULL;
	while(n)
	{
		ft_putchar('>');
		n = read(0, buf, 512);
		ft_memjoin((void **)&cl_input, (void *)buf, cl_input_len, n);
		cl_input_len += n;
	}
	ft_memjoin((void **)&cl_input, (void *)"\0", cl_input_len, 1);
	printf("cl_input = %s\n", cl_input);
	free(cl_input);
}

