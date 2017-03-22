/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:06:41 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/09 19:32:43 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*return_empty(void)
{
	char		*res;

	res = (char *)malloc(1);
	res[0] = 0;
	return (res);
}

static	char	*return_res(int i, int j, char *ans, const char *s)
{
	int k;

	k = 0;
	while (i <= j)
	{
		ans[k] = s[i];
		k++;
		i++;
	}
	return (ans);
}

char			*ft_strtrim(char const *s)
{
	char		*ans;
	int			i;
	int			j;

	i = 0;
	if (s == NULL || s[i] == '\0')
		return ((char*)s);
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != 0)
		++i;
	if (s[i] == 0)
		return (return_empty());
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		--j;
	ans = ft_strnew(j - i + 1);
	if (ans == NULL)
		return (NULL);
	ans = return_res(i, j, ans, s);
	return (ans);
}
