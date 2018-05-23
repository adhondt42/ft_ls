/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:33:58 by jtaibi            #+#    #+#             */
/*   Updated: 2017/12/09 18:36:31 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first;
	t_list *tmp;

	tmp = f(lst);
	if ((new = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
		return (NULL);
	first = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if ((new->next = ft_lstnew(tmp->content, tmp->content_size)) == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
