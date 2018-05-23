/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:16:14 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/24 11:13:24 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*createpath(char *path, char *name)
{
	char	*ret;
	char	*tmp;

	if (!(path))
		return (ft_strdup(name));
	tmp = ft_strjoin(path, "/");
	ret = ft_strjoin(tmp, name);
	free(tmp);
	return (ret);
}
