/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:41:10 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/23 16:41:12 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_color(char *str, char *color)
{
	int				i;
	static char		*colors[9] = {"black", "red", "green", "yellow", "blue",
		"lred", "lblue", "lgreen", "lcyan"};
	static char		*codes[9] = {"30m", "31m", "32m;", "33m", "34m", "91m",
		"94m", "92m", "96m"};

	i = 0;
	while (i < 7 && ft_strcmp(colors[i], color) != 0)
		i++;
	ft_putstr("\033[");
	ft_putstr(codes[i]);
	ft_putstr(str);
	ft_putstr("\033[39m");
}
