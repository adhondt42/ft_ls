/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:09:46 by jtaibi            #+#    #+#             */
/*   Updated: 2018/03/04 22:23:18 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpyc(const char *str, char c)
{
	char	*new;
	int		i;
	int		x;

	i = ft_index(str, c) + 1;
	if ((new = (char *)malloc(sizeof(char) * ft_strlen(str) - i)) == NULL)
		return (NULL);
	x = 0;
	while (str[i + x])
	{
		if (str[i + x] != c)
		{
			new[x] = str[i + x];
			x++;
		}
		else
			i++;
	}
	new[i + x] = '\0';
	return (new);
}
