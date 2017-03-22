/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 22:35:50 by rishchen          #+#    #+#             */
/*   Updated: 2016/12/12 22:37:36 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*curr;
	t_list	*next;

	curr = lst;
	next = curr;
	while (next)
	{
		next = curr->next;
		(*f)(curr);
		curr = next;
	}
}
