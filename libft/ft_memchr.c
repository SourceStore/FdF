/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:06:50 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/09 19:34:25 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		*s1;

	str = s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
		{
			s1 = (unsigned char *)str;
			return (s1);
		}
		str++;
		n--;
	}
	return (NULL);
}
