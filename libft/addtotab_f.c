/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addtotab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 10:35:01 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 16:40:30 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**addtotab_f(char **tab, char *str, size_t i)
{
	int		tablen;
	char	**ret;

	tablen = ft_tablen(tab);
	if ((ret = (char **)malloc(sizeof(char *) * (tablen + 2))) == NULL)
		return (NULL);
	ret[tablen + 1] = NULL;
	ret[tablen] = ft_strdup(str);
	while (--tablen >= 0)
		ret[tablen] = ft_strdup(tab[tablen]);
	if (i == 1 || i == 3)
		ft_freetab(tab);
	if (i == 2 || i == 3)
		free(str);
	return (ret);
}
