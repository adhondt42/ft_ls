/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 18:22:51 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/24 12:00:51 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			sorttab_time(char *path, char **tab)
{
	int			i;
	struct stat	*s1;
	struct stat	*s2;

	i = 0;
	while (tab[i + 1])
	{
		s1 = get_lstats(path, tab[i]);
		s2 = get_lstats(path, tab[i + 1]);
		if (!s1 || !s2)
			return ;
		if (s1->st_mtime < s2->st_mtime)
		{
			ft_swapptr(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
		free(s1);
		free(s2);
	}
}

void			sort(t_ls *s, char *path, char **tab)
{
	if (!(tab) || !(tab[0]))
		return ;
	sorttab_ascii(tab);
	if (s->flist[3] == 't')
		sorttab_time(path, tab);
	if (s->flist[2] == 'r')
		sorttab_rev(tab);
}
