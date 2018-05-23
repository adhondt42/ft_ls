/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltools.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:25:44 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 18:13:41 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*get_pwuid(struct stat *st)
{
	struct passwd	*pw;
	char			*owner;

	if (!(pw = getpwuid(st->st_uid)))
		owner = ft_itoa(st->st_uid);
	else
		owner = ft_strdup(pw->pw_name);
	return (owner);
}

char				*get_grgid(struct stat *st)
{
	struct group	*gr;
	char			*group;

	if (!(gr = getgrgid(st->st_gid)))
		group = ft_itoa(st->st_uid);
	else
		group = ft_strdup(gr->gr_name);
	return (group);
}

void				get_dev(t_ls *s, int st_rdev)
{
	putnbns(major(st_rdev), s->majormax - ft_intlen(major(st_rdev)), 0);
	ft_putchar(',');
	putnbns(minor(st_rdev), s->minormax - ft_intlen(minor(st_rdev)), 0);
	return ;
}

struct stat			*get_stats(char *path, char *name)
{
	char			*tmp;
	struct stat		*s;

	if (!(s = (struct stat *)malloc(sizeof(struct stat))))
		return (NULL);
	tmp = createpath(path, name);
	if ((lstat(tmp, s)) == -1)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (s);
}
