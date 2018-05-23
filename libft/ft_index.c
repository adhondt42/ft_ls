/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:49:09 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 16:49:13 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_index(const char *str, char c)
{
	int index;

	index = 0;
	while (str[index] && str[index] != c)
		index++;
	return (index);
}
