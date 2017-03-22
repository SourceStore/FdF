/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_det_mat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:07:17 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/14 16:47:26 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	float		*t_b_t(float *p)
{
	float			*mat;
	float			buff;
	float			ans;
	float			*ans2;

	mat = p;
	ans = 0;
	buff = *(mat + 0 * 3 + 0) * (*(mat + 1 * 3 + 1)) * (*(mat + 2 * 3 + 2));
	ans += buff;
	buff = *(mat + 0 * 3 + 0) * (*(mat + 1 * 3 + 2))\
		* (*(mat + 2 * 3 + 1)) * -1;
	ans += buff;
	buff = *(mat + 0 * 3 + 1) * (*(mat + 1 * 3 + 0))\
		* (*(mat + 2 * 3 + 2)) * -1;
	ans += buff;
	buff = *(mat + 0 * 3 + 1) * (*(mat + 1 * 3 + 2)) * (*(mat + 2 * 3 + 0));
	ans += buff;
	buff = *(mat + 0 * 3 + 2) * (*(mat + 1 * 3 + 0)) * (*(mat + 2 * 3 + 1));
	ans += buff;
	buff = *(mat + 0 * 3 + 2) * (*(mat + 1 * 3 + 1))\
		* (*(mat + 2 * 3 + 0)) * -1;
	ans += buff;
	ans2 = &ans;
	return (ans2);
}

static	float		*tw_b_tw(float *p)
{
	float			ans;
	float			*mat;
	float			*ans2;

	ans = 0;
	mat = p;
	ans = *(mat + 0 * 2 + 0) * (*(mat + 1 * 2 + 1)) -\
			(*(mat + 1 * 2 + 0)) * (*(mat + 0 * 2 + 1));
	ans2 = &ans;
	return (ans2);
}

void				*ft_det_mat(float *p, int n)
{
	float			*ans;

	if (n > 3 || n < 1)
		return (NULL);
	else if (n == 3)
	{
		ans = t_b_t(p);
		return (ans);
	}
	else if (n == 2)
	{
		ans = tw_b_tw(p);
		return (ans);
	}
	else
	{
		ans = (p + 1 * 0);
		return (ans);
	}
	return (NULL);
}
