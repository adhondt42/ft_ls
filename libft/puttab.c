/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tabtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:24:20 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/16 19:46:38 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		puttab(char **tab, char *end)
{
	int i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i++]);
		if (end)
			ft_putstr(end);
	}
}
