/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:21:33 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/13 16:22:14 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	n += 1;
	while (--n)
	{
		if (*s1 != *s2)
			return ((*(unsigned char *)s1) - (*(unsigned char *)s2));
		else if (!*s1)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
