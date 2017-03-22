/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:37:12 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/14 16:31:17 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*c;
	size_t	i;

	i = 0;
	if (size > 2147483647)
		return (NULL);
	c = (char *)malloc(sizeof(char) * size);
	if (c == NULL)
		return (NULL);
	else
	{
		while (i <= size)
		{
			*(c + i) = 0;
			i++;
		}
		*(c + i) = 0;
		return (c);
	}
}
