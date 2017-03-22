/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:23:03 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/09 14:01:11 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *str, int c, size_t n)
{
	char	symb;
	size_t	i;

	symb = c;
	i = 0;
	while (i < n)
	{
		(((char *)str)[i]) = symb;
		i++;
	}
	return (str);
}
