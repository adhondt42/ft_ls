/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorttab_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 19:01:39 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/18 15:05:50 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			sorttab_rev(char **tab)
{
	int			i;
	char		*tmp;

	i = 0;
	while (i < (int)tablen(tab) - i - 1)
	{
		tmp = tab[i];
		tab[i] = tab[tablen(tab) - i - 1];
		tab[tablen(tab) - i - 1] = tmp;
		i++;
	}
}
