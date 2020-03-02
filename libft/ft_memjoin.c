/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:48:18 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/02 17:36:18 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_memjoin(void **dst, void *src, size_t dst_len, size_t src_len)
{
	char	*buf;

	if (dst == NULL || src == NULL || src_len == 0)
	{
		return ;
	}
	if (*dst == NULL && dst_len == 0)
	{
		*dst = (void *)malloc(sizeof(char) * src_len);
		ft_memcpy(*dst, src, src_len);
	}
	else
	{
		buf = (char *)malloc(sizeof(char) * dst_len);
		ft_memcpy((void *)buf, *dst, dst_len);
		free(*dst);
		*dst = (void *)malloc(sizeof(char) * (dst_len + src_len));
		ft_memcpy(*dst, (void *)buf, dst_len);
		ft_memcpy((void *)&((*dst)[dst_len]), src, src_len);
		free(buf);
	}
}
