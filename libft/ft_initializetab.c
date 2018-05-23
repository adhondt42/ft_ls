/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initializetab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:27:52 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/12 11:07:52 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_initializetab(size_t size)
{
	char	**tab;

	if ((tab = (char **)malloc(sizeof(char *) * size)) == NULL)
		return (NULL);
	while (size > 0)
		tab[--size] = NULL;
	return (tab);
}
