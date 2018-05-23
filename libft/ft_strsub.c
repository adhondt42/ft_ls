/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 12:45:32 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/24 12:45:36 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(len + 1 * sizeof(char));
	if (!new || !s)
		return (NULL);
	while (i < len)
	{
		new[i] = s[(size_t)start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
