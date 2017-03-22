/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:26:56 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/13 16:03:01 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ans;

	ans = ft_strstr(big, little);
	if ((ans - big) + ft_strlen(little) > len)
		return (NULL);
	return (ans);
}
