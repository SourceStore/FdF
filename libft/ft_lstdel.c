/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:27:10 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/13 17:16:07 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *ans;

	ans = *alst;
	while (*alst)
	{
		ans = *alst;
		*alst = ans->next;
		del(ans->content, ans->content_size);
		free(ans);
	}
	free(*alst);
	alst = NULL;
}
