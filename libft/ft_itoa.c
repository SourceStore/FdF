/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:58:05 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/09 16:21:30 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			counter(int n)
{
	int				i;

	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (10);
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

static	char		*mem(int n, int c)
{
	char			*str;

	if (n < 0)
	{
		str = ft_strnew(c + 1);
		if (!str)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		str = ft_strnew(c);
		if (str == NULL)
			return (NULL);
	}
	return (str);
}

char				*ft_itoa(int n)
{
	unsigned int	j;
	int				c;
	char			*str;

	c = counter(n);
	str = mem(n, c);
	if (str == NULL)
		return (NULL);
	if (n < 0)
		j = (unsigned int)(n * -1);
	else
		j = (unsigned int)n;
	while (c > 0)
	{
		if (str[0] != '-')
			str[c - 1] = (char)((j % 10) + 48);
		else
			str[c] = (char)((j % 10) + 48);
		j /= 10;
		c--;
	}
	return (str);
}
