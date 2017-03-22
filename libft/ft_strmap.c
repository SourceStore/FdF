/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:25:58 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/09 19:23:39 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*ans;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	else
	{
		j = -1;
		i = ft_strlen(s);
		ans = ft_strnew(i);
		if (ans == NULL)
			return (NULL);
		while (++j < i)
		{
			ans[j] = f(s[j]);
		}
		return (ans);
	}
}
