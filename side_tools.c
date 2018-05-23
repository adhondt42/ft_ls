/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:29:38 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/24 11:53:23 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_error(char *path)
{
	ft_putstr("ft_ls: ");
	ft_putstr(path);
	ft_putstr(": ");
	ft_putlstr(strerror(errno));
}

void			usage(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ft_ls [-lartRGg] [file ...]\n");
	exit(0);
}

void			putdir(t_ls *s, char *path)
{
	if ((s->flist[4] != 'R' && s->files[0] == NULL && s->paths[1] == NULL))
		return ;
	if (ft_strcmp(path, ".") != 0)
		ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
}

void			puttotal(t_ls *s)
{
	if (s->totalbehavior == 0)
		return ;
	if (s->nbblocks > -1)
	{
		ft_putstr("total ");
		ft_putnbr(s->nbblocks);
		ft_putchar('\n');
		s->nbblocks = -1;
	}
}

void			putsymlink(int st_mode, char *path, char *name)
{
	char		*tmp;
	char		buff[1024];
	int			linksize;

	if (S_ISLNK(st_mode))
	{
		tmp = createpath(path, name);
		if ((linksize = readlink(tmp, buff, 1024)))
		{
			buff[linksize] = '\0';
			ft_putstr(" -> \e[1;33;40m");
			ft_putstr(buff);
			ft_putstr("\e[0m");
		}
		free(tmp);
	}
	ft_putchar('\n');
}
