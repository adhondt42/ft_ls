/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:26:39 by jtaibi            #+#    #+#             */
/*   Updated: 2018/03/25 23:16:26 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	else if (!s2)
		return (ft_strdup(s1));
	else if (!s1)
		return (ft_strdup(s2));
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(s1) + n + 1)))
		return (NULL);
	ft_strcpy(new, s1);
	ft_strncpy((new + ft_strlen(s1)), s2, n);
	return (new);
}
