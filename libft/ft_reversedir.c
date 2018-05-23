/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversedir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:46:09 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 16:46:11 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dir	*ft_reversedir(t_dir **dir)
{
	t_dir	*tmp;
	t_dir	*stock;
	t_dir	*ret;

	tmp = *dir;
	while (tmp->next)
		tmp = tmp->next;
	ret = tmp;
	while (tmp->before)
	{
		stock = tmp->before;
		tmp->before = tmp->next;
		tmp->next = stock;
		tmp = stock;
	}
	return (ret);
}
