/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 12:44:43 by jtaibi            #+#    #+#             */
/*   Updated: 2018/03/31 20:50:18 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, int index, int len)
{
	char	*new;

	if (len - 1 >= (int)ft_strlen(str))
	{
		free(str);
		str = NULL;
		return (ft_strdup(""));
	}
	if ((new = ft_strnew(ft_strlen(str) - len - index + 1)) == NULL)
		return (str);
	ft_strncpy(new, str, index);
	ft_strcpy(new + index, str + index + len);
	free(str);
	str = NULL;
	return (new);
}
