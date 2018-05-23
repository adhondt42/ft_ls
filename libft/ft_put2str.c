/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:44:58 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/24 12:45:00 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put2str(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putlstr(tab[i]);
		i++;
	}
}