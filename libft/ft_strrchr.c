/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:15:53 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/14 15:16:24 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s1;

	s1 = (char *)s;
	i = ft_strlen(s1) + 1;
	while (--i >= 0)
	{
		if (s1[i] == (char)c)
			return (&s1[i]);
	}
	return (NULL);
}
