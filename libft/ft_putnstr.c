/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:47:17 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 16:47:21 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
