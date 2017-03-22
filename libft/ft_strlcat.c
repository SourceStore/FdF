/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:35:38 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/09 20:00:28 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	m;

	s = 0;
	m = 0;
	while (dst[m])
		m++;
	while (src[s] && (m + 1) < size)
		dst[m++] = src[s++];
	dst[m] = '\0';
	if (!s)
		m = size;
	while (src[s++])
		m++;
	return (m);
}
