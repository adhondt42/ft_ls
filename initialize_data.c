/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:27:21 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/24 12:33:22 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_paths(t_ls *s, int argc)
{
	DIR	*dir;

	s->i = 0;
	s->paths = ft_initializetab(1);
	if (!(s->files = ft_initializetab(1)) || !(s->paths))
		return ;
	if (s->y >= argc)
	{
		s->paths = addtotab_f(s->paths, ft_strdup("."), 3);
		return ;
	}
	while (s->y < argc)
	{
		if ((dir = opendir(s->argv[s->y])))
		{
			s->paths = addtotab_f(s->paths, s->argv[s->y], 1);
			closedir(dir);
		}
		else if (errno == ENOTDIR)
			s->files = addtotab_f(s->files, s->argv[s->y], 1);
		else
			print_error(s->argv[s->y]);
		s->y++;
	}
}

void	place_flags(t_ls *s, char *arg)
{
	int	index;

	s->x = 1;
	while (arg[s->x])
	{
		index = ft_index(s->flags, arg[s->x]);
		if (index >= 0 && index < (int)ft_strlen(s->flags))
			s->flist[index] = s->flags[index];
		else
			usage(arg[s->x]);
		s->x++;
	}
}

void	get_flags(t_ls *s)
{
	s->y = 1;
	s->flags = "lartRGg";
	s->flist = ft_strdup("       ");
	while (s->argv[s->y])
	{
		if (ft_strcmp(s->argv[s->y], "--") == 0)
		{
			s->y++;
			break ;
		}
		else if (s->argv[s->y][0] == '-' &&
				ft_strlen(s->argv[s->y]) > 1)
			place_flags(s, s->argv[s->y]);
		else if (ft_strlen(s->argv[s->y]) == 1 &&
				s->argv[s->y][0] == '-')
			usage('-');
		else
			break ;
		s->y++;
	}
}
