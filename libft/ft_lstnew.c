/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:43:04 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/12 19:10:20 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ans;

	ans = (t_list*)malloc(sizeof(t_list));
	if (!ans)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		ans->content_size = 0;
		ans->content = NULL;
	}
	else
	{
		ans->content = malloc(sizeof(content_size));
		ans->content = ft_memcpy(ans->content, content, content_size);
		ans->content_size = content_size;
	}
	ans->next = NULL;
	return (ans);
}
