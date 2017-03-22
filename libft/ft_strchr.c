/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:02:35 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/14 15:16:06 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*s1;

	s1 = (char *)s;
	if (c == 0)
		return (s1 + ft_strlen(s1));
	while (*s1)
	{
		if (*s1 == (char)c)
			return (s1);
		s1++;
	}
	return (NULL);
}
