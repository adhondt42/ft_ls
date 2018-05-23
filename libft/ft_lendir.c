/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lendir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:50:38 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 16:50:54 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lendir(char *path, int err, int cache)
{
	struct dirent	*dir_ent;
	DIR				*dir;
	int				len_dir;

	len_dir = 0;
	if (!(dir = opendir(path)) && err != 0)
		ft_erno(path);
	while ((dir_ent = readdir(dir)) != NULL)
	{
		if (cache == 0 && dir_ent->d_name[0] == '.')
			;
		else
			len_dir++;
	}
	free(dir_ent);
	closedir(dir);
	return (len_dir);
}
