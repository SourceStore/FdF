/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:26:08 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/13 17:13:03 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ans;

	if (s)
	{
		ans = (char *)malloc((len + 1) * sizeof(char));
		if (ans)
		{
			ans = (char *)ft_memcpy(ans, (void *)(s + start), len);
			ans[len] = '\0';
			return (ans);
		}
	}
	return (NULL);
}
