/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:42:56 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 16:42:57 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapint(int *i1, int *i2)
{
	int		tmp;

	tmp = *i1;
	*i1 = *i2;
	*i2 = tmp;
}
