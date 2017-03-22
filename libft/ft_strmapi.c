/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:14:04 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/09 20:27:35 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ans;
	size_t	i;
	size_t	j;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	ans = ft_strnew(j);
	if (ans == NULL)
		return (NULL);
	while (i < j)
	{
		ans[i] = f(i, s[i]);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
