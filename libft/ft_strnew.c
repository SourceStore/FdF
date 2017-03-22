/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:42:24 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/13 16:05:11 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc((size + 1) * sizeof(char));
	if (str)
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	return (NULL);
}
