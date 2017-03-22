/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_mat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:50:06 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/14 17:34:48 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	float	*quad(float *matr, int n, int m)
{
	float		*ans;
	int			i;
	int			j;

	ans = (float *)malloc(sizeof(float) * m * n);
	i = 0;
	j = 0;
	while (i < n)
	{
		while (j < m)
		{
			*(ans + j * n + i) = *(matr + i * m + j);
			j++;
		}
		j = 0;
		i++;
	}
	return (ans);
}

void			*ft_rev_mat(float *matr, int n, int m)
{
	float		*ans;

	if (n > 0 && m > 0 && m < 11 && n < 11)
	{
		ans = quad(matr, n, m);
		return (ans);
	}
	return (NULL);
}
