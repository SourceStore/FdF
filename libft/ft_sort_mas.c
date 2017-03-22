/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:56:59 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/14 16:14:19 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sort_mas(float *mas, int n)
{
	int		i;
	int		j;
	float	x;

	i = 1;
	if (n > 0)
	{
		while (i < n)
		{
			x = *(mas + i * 1);
			j = i;
			while (j > 0 && *(mas + (j - 1) * 1) > x)
			{
				*(mas + j * 1) = *(mas + (j - 1) * 1);
				j--;
			}
			*(mas + j * 1) = x;
			i++;
		}
	}
}
