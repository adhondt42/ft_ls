/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaplst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:42:30 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 16:42:45 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swaplst(t_list *lst1, t_list *lst2)
{
	t_list	*tmp;

	tmp = lst2;
	lst1->next = lst2->next;
	lst2->next = lst1;
	lst2->before = lst1->before;
	lst1->before = tmp;
}
