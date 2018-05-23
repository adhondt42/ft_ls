/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:49:55 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 16:50:09 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdir(char *path)
{
	struct stat		*stats;

	if (!(stats = (struct stat *)malloc(sizeof(struct stat))))
		return (-1);
	lstat(path, stats);
	if (ft_ftype(stats->st_mode) == 'd')
	{
		free(stats);
		return (1);
	}
	free(stats);
	return (0);
}
