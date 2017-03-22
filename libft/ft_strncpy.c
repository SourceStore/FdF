/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:28:18 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/13 16:25:48 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t			i;
	unsigned int	j;

	i = 0;
	j = -1;
	while (++j < len)
		dst[j] = '\0';
	while (i < len && *src)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	return (dst);
}
