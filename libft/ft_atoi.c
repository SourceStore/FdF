/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:15:25 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/14 16:34:01 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int	cond;

	cond = 1;
	i = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' && *(str + 1) >= '0' && *(str + 1) <= '9')
	{
		cond *= -1;
		str++;
	}
	else if (*str == '+' && *(str + 1) >= '0' && *(str + 1) <= '9')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + *str - '0';
		str++;
	}
	return (i * cond);
}
