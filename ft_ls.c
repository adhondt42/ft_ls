/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:26:30 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/24 15:39:04 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	putstrr(char *path, char *dir)
{
	ft_putstr(path);
	ft_putstr(":\n");
	ft_putstr("ft_ls: ");
	ft_putstr(dir);
	ft_putchar(' ');
	ft_putstr(strerror(errno));
	ft_putstr("\n\n");
}

int		ft_ls2(t_ls *s, DIR *dirtmp, char *path, char *dir)
{
	char	*tmp;

	if (!(tmp = createpath(path, dir)))
		return (0);
	if (!(dirtmp = opendir(tmp)) && errno != ENOTDIR && !ft_strequ(dir, ".")
			&& !ft_strequ(dir, ".."))
		putstrr(path, dir);
	else if ((dirtmp) && !ft_strequ(dir, ".") &&
			!ft_strequ(dir, ".."))
		ft_ls(s, tmp);
	else if (errno == ENOTDIR && ft_strequ(path, "/dev//fd") &&
			ft_strequ(dir, "3"))
		putstrr(path, dir);
	if (dirtmp)
		closedir(dirtmp);
	free(tmp);
	return (1);
}

void	ft_ls(t_ls *s, char *path)
{
	int		i;
	char	**dir;
	DIR		*dirtmp;

	dirtmp = NULL;
	putdir(s, path);
	if (!(dir = ft_readdir(path, (s->flist[1] == 'a' ? 1 : 0))))
	{
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		return ;
	}
	sort(s, path, dir);
	s->nbblocks = 0;
	if (s->flist[0] == 'l' && (s->init = 0) == 0 && tablen(dir) > 0)
		putlnames(s, tablen(dir) - 1, dir, path);
	else if (tablen(dir) == 0)
		puttotal(s);
	else
		puttab(dir, "\n");
	i = 0;
	while (s->flist[4] == 'R' && ft_ls2(s, dirtmp, path, dir[i]))
		i++;
	ft_freetab(dir);
}

int		main(int argc, char **argv)
{
	int				i;
	t_ls			*s;

	if (!(s = (t_ls *)malloc(sizeof(t_ls))))
		return (-1);
	s->totalbehavior = 0;
	s->argv = argv;
	s->init = 0;
	get_flags(s);
	get_paths(s, argc);
	sort(s, "./", s->files);
	sort(s, "./", s->paths);
	if (s->files[0])
		s->flist[0] == 'l' ? putlnames(s, tablen(s->files) - 1,
				s->files, "./") : putpaths(s, s->files);
	i = -1;
	s->totalbehavior = 1;
	while (s->paths && s->paths[++i])
	{
		ft_ls(s, s->paths[i]);
		(s->paths[i + 1] == NULL) ? 0 : ft_putchar('\n');
	}
	free(s->flist);
	ft_free2tab(s->files, s->paths);
	return (1);
}
