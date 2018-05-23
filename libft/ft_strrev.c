/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:21:49 by jtaibi            #+#    #+#             */
/*   Updated: 2017/12/15 13:32:40 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	char	*rev;
	int		len;
	int		x;

	if ((rev = (char *)malloc(sizeof(char) * ft_strlen(str))) == NULL)
		return (NULL);
	len = ft_strlen(str);
	x = 0;
	while (x < len)
	{
		rev[x] = str[len - 1 - x];
		x++;
	}
	rev[x] = '\0';
	return (rev);
}
