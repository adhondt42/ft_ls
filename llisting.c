/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llinsting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:28:52 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/24 12:39:09 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				init_l(t_ls *s)
{
	if (s->init == 1)
		return ;
	s->blocksmax = 0;
	s->linkmax = 0;
	s->ownermax = 0;
	s->groupmax = 0;
	s->bytesmax = 0;
	s->init = 1;
}

void				get_devstats(t_ls *s, char *path, char **tab, int i)
{
	struct stat		*st;
	char			*owner;
	char			*group;
	int				len;

	len = ft_lendir(path, 1, 1);
	while (i < len - 1)
	{
		st = get_stats(path, tab[i]);
		owner = get_pwuid(st);
		group = get_grgid(st);
		putrights(st->st_mode);
		putnbns(st->st_nlink, s->linkmax - ft_intlen(st->st_nlink), 0);
		if (s->flist[6] == ' ')
			putns(owner, s->ownermax - ft_strlen(owner), 0);
		if (s->flist[5] == ' ')
			putns(group, s->groupmax - ft_strlen(group), 0);
		ft_putchar(' ');
		st->st_rdev ? get_dev(s, st->st_rdev) : putnbns(st->st_size, 7, 0);
		putdate(st->st_mtime);
		get_color(path, tab[i]);
		free3(st, owner, group);
		ft_putchar('\n');
		i++;
	}
}

void				putii(t_ls *s, struct stat *st, char *owner, char *group)
{
	puttotal(s);
	putrights(st->st_mode);
	putnbns(st->st_nlink, s->linkmax - ft_intlen(st->st_nlink), 0);
	if (s->flist[6] == ' ')
		putns(owner, s->ownermax - ft_strlen(owner), 0);
	if (s->flist[5] == ' ')
		putns(group, s->groupmax - ft_strlen(group), 0);
	ft_putchar(' ');
}

void				putlnames(t_ls *s, int i, char **dir, char *path)
{
	struct stat		*st;
	char			*owner;
	char			*group;

	if (!(st = get_stats(path, dir[i])))
	{
		if ((ft_strcmp(path, "/dev//fd")) == 0 || (ft_strequ(path, "/dev/fd")))
			get_devstats(s, path, dir, 0);
		return ;
	}
	owner = get_pwuid(st);
	group = get_grgid(st);
	init_l(s);
	checkmax(s, st, owner, group);
	(i > 0) ? putlnames(s, i - 1, dir, path) : 0;
	putii(s, st, owner, group);
	if (S_ISBLK(st->st_mode) || S_ISCHR(st->st_mode))
		get_dev(s, st->st_rdev);
	else
		(ft_strncmp(path, "/dev", 4) == 0) ? putnbns(st->st_size, 6, 0) :
			putnbns(st->st_size, s->bytesmax - ft_intlen(st->st_size) - 1, 0);
	putdate(st->st_mtime);
	get_color(path, dir[i]);
	putsymlink(st->st_mode, path, dir[i]);
	free3(st, owner, group);
}
