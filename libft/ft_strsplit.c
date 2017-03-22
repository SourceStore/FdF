/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:23:29 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/10 14:10:10 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		c_words(char const *s, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			++j;
		i++;
	}
	return (j);
}

static	char	**c_chars(char const *s, char c, char **ans)
{
	int			i;
	int			j;
	int			k;
	int			start;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			j++;
		}
		if (j > 0)
			ans[k] = ft_strsub(&(s[start]), 0, j);
		j = 0;
		k++;
	}
	return (ans);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**ans;

	if (s == NULL || s == (char *)0)
		return (NULL);
	else
	{
		ans = (char **)malloc(sizeof(char *) * (c_words(s, c) + 1));
		if (ans == NULL)
			return (NULL);
		ans[c_words(s, c)] = 0;
		ans = c_chars(s, c, ans);
	}
	return (ans);
}
