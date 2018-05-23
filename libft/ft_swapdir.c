/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:42:01 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 16:42:06 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapdir(t_dir *d1, t_dir *d2)
{
	t_dir	*tmp;
	t_dir	*tmp2;

	tmp = d2->next;
	tmp2 = d2->before;
	d2->next = d1->next;
	d2->before = d1->before;
	d1->next = tmp;
	d1->before = tmp2;
	d1->next->before = d1;
	if (d1->before)
		d1->before->next = d1;
	d2->next->before = d2;
	if (d2->before)
		d2->before->next = d2;
}
