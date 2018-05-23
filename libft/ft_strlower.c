/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:44:33 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 16:44:34 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlower(char *str)
{
	int		i;
	char	*new;

	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (str);
	i = 0;
	while (str[i])
	{
		if (ft_isupper(str[i]))
			new[i] = str[i] + 32;
		else
			new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
