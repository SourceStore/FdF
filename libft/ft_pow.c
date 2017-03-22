/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:38:06 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/14 18:13:09 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float		ft_pow(float n, int m)
{
	int		i;
	float	ans;

	i = 0;
	ans = 1.0;
	if (m > 0)
	{
		while (i < m)
		{
			ans *= n;
			i++;
		}
	}
	else if (m == 0)
		return (1);
	else
	{
		while (i > m)
		{
			ans *= 1 / n;
			i--;
		}
	}
	return (ans);
}
