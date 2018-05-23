/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:18:16 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/17 17:19:15 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct stat		*get_lstats(char *path, char *name)
{
	char		*tmp;
	struct stat	*s;

	tmp = createpath(path, name);
	if (!(s = (struct stat *)malloc(sizeof(struct stat))))
		return (NULL);
	lstat(tmp, s);
	free(tmp);
	return (s);
}
