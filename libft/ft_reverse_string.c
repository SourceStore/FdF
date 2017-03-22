/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:20:55 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/13 18:06:55 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_reverse_string(char *s)
{
	int		len;
	char	*ans;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	else
	{
		len = ft_strlen(s);
		ans = ft_strnew(len);
		i = 0;
		j = len - 1;
		if (!*ans)
		{
			while (i < len)
			{
				ans[i] = s[j];
				i++;
				j--;
			}
			return (ans);
		}
		return (NULL);
	}
}
