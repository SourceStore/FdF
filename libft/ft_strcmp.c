/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:53:37 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/13 16:21:09 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if ((*s1 == '\0' && *s2 == '\0') || (s1 == NULL || s2 == NULL))
		return (0);
	while (*s1 || *s2)
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
