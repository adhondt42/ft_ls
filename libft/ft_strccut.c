/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:23:42 by jtaibi            #+#    #+#             */
/*   Updated: 2018/03/04 22:26:44 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strccut(char *str, int index, char c)
{
	char	*new;
	int		len;
	int		i;

	len = 0;
	while (str[index + len] == c)
		len++;
	while (str[index + len] != c)
		len++;
	if ((new = (char *)malloc(sizeof(char) * ft_strlen(str) - len + 1)) == NULL)
		return (NULL);
	i = -1;
	while (i++ < index - 1)
		if (str[i] != c)
			new[i] = str[i];
	while (str[i + len])
	{
		new[i] = str[i + len + 1];
		i++;
	}
	new[i] = '\0';
	return (new);
}
