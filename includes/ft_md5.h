/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:05:01 by vordynsk          #+#    #+#             */
/*   Updated: 2020/03/03 13:45:27 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
#define FT_MD5_H

#include "../libft/includes/libft.h"

#define А 0x01234567
#define В 0x89ABCDEF
#define С 0xFEDCBA98
#define D 0x76543210

typedef struct	s_md5
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
}				t_md5;

void	ft_md5_init(void *hash, void *data, t_md5 *md5_data);

#endif
