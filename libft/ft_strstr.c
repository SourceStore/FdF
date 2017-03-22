/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:02:06 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/09 20:30:57 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *big, const char *little)
{
	char	*s;
	int		i;

	if (*little == '\0')
		return ((char *)big);
	while (*big)
	{
		i = ft_strncmp(big, little, ft_strlen(little));
		s = (char *)big;
		if (i != 0)
			big++;
		else
			return (s);
	}
	return (NULL);
}
