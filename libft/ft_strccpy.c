/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:27:20 by jtaibi            #+#    #+#             */
/*   Updated: 2018/03/04 22:27:23 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(const char *str, char c)
{
	char	*new;
	int		i;
	int		x;

	i = 0;
	x = ft_strclen(str, c);
	new = (char *)malloc(sizeof(char) * x + 1);
	if (!str || !new)
		return (NULL);
	while (i < x && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
