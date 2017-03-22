/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:37:39 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/09 19:28:43 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf;
	size_t			i;

	i = 0;
	buf = (unsigned char*)malloc(len);
	if (buf)
	{
		while (i < len)
		{
			buf[i] = ((unsigned char *)src)[i];
			i++;
		}
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = buf[i];
			i++;
		}
	}
	free(buf);
	return (dst);
}
