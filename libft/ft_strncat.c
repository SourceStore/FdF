/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 13:46:46 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/09 19:50:13 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(s1);
	k = ft_strlen(s2);
	while (i < n && i < k)
	{
		*(s1 + j) = s2[i];
		j++;
		i++;
	}
	s1[j] = '\0';
	return (s1);
}
