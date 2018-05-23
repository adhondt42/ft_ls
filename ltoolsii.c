/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoolsii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:25:11 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/30 16:20:20 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_abs(long long sec)
{
	if (sec < 0)
		return (sec * -1);
	return (sec);
}

void			putdate(time_t atime)
{
	char		*date;

	date = ctime(&atime);
	ft_putnstr((date + 3), ft_strlen(date) - 17);
	if (ft_abs(time(NULL) - atime) > 15768017)
	{
		ft_putchar(' ');
		ft_putnstr((date + ft_strlen(date) - 6), 5);
	}
	else
		ft_putnstr((date + ft_strlen(date) - 15), 6);
	ft_putchar(' ');
}

void			putrights(int st_mode)
{
	int			i;
	static int	expt[3] = {S_ISUID, S_ISGID, S_ISVTX};
	static int	mask[9] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP,
		S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
	static char	rights[9] = {'r', 'w', 'x', 'r', 'w', 'x', 'r', 'w', 'x'};

	i = 0;
	ft_putchar(ft_ftype(st_mode));
	while (mask[i] && i < 9)
	{
		if ((st_mode & expt[0]) && i == 2)
			(st_mode & mask[2]) ? ft_putchar('s') : ft_putchar('S');
		else if ((st_mode & expt[1]) && i == 5)
			(st_mode & mask[5]) ? ft_putchar('s') : ft_putchar('S');
		else if ((st_mode & expt[2]) && i == 8)
			(st_mode & mask[8]) ? ft_putchar('t') : ft_putchar('T');
		else if (st_mode & mask[i])
			ft_putchar(rights[i]);
		else
			ft_putchar('-');
		i++;
	}
	ft_putchar(' ');
}

void			checkmax(t_ls *s, struct stat *st, char *owner, char *group)
{
	s->nbblocks += st->st_blocks;
	if (!s->blocksmax || ft_intlen(st->st_blocks) > s->blocksmax)
		s->blocksmax = ft_intlen(st->st_blocks);
	if (!s->linkmax || ft_intlen(st->st_nlink) > s->linkmax)
		s->linkmax = ft_intlen(st->st_nlink);
	if (!s->ownermax || (int)ft_strlen(owner) > s->ownermax)
		s->ownermax = ft_strlen(owner);
	if (!s->groupmax || (int)ft_strlen(group) > s->groupmax)
		s->groupmax = ft_strlen(group);
	if (!st->st_rdev &&
			(!s->bytesmax || ft_intlen(st->st_size) > s->bytesmax))
		s->bytesmax = ft_intlen(st->st_size);
	if (st->st_rdev &&
			(!s->majormax || ft_intlen(major(st->st_rdev)) > s->majormax))
		s->majormax = ft_intlen(major(st->st_rdev));
	if (st->st_rdev &&
			(!s->minormax || ft_intlen(minor(st->st_rdev)) > s->minormax))
		s->minormax = ft_intlen(minor(st->st_rdev));
}
