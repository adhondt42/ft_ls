/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:41:07 by jtaibi            #+#    #+#             */
/*   Updated: 2017/12/09 18:05:13 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *nxt;

	tmp = *alst;
	while (tmp)
	{
		del(tmp->content, tmp->content_size);
		nxt = tmp;
		free(tmp);
		tmp = nxt->next;
	}
	*alst = NULL;
}
