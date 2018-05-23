/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:30:47 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 17:46:28 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				putnbns(int str, int n, int a)
{
	char			*tmp;

	tmp = ft_itoa(str);
	putns(tmp, n, a);
	free(tmp);
}

void				putns(char *str, int n, int a)
{
	int				i;

	i = -1;
	while (!a && ++i < n + 1)
		ft_putchar(' ');
	ft_putstr(str);
	while (a && ++i < n + 1)
		ft_putchar(' ');
}

void				putpaths(t_ls *s, char **tab)
{
	int				i;
	DIR				*dir;

	i = 0;
	while (tab[i] && ft_strcmp(tab[0], ".") != 0)
	{
		if (!(dir = opendir(tab[i])))
			ft_putlstr(tab[i]);
		if (dir)
			closedir(dir);
		i++;
	}
	s->paths_size = i;
}

void				get_color(char *path, char *str)
{
	char			*tmp;
	struct stat		*stats;

	tmp = createpath(path, str);
	if (!(stats = get_stats(path, str)))
	{
		ft_putstr(str);
		free(tmp);
		return ;
	}
	lstat(tmp, stats);
	if (ft_ftype(stats->st_mode) == 'd' || ft_ftype(stats->st_mode) == 'l')
		ft_color(str, "lblue");
	else if (stats->st_mode & S_IXUSR || stats->st_mode & S_IXGRP ||
			stats->st_mode & S_IXOTH)
		ft_color(str, "lgreen");
	else
		ft_putstr(str);
	free(tmp);
	free(stats);
}
