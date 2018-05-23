/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhondt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 12:14:51 by adhondt           #+#    #+#             */
/*   Updated: 2018/04/24 11:42:50 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <time.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct				s_ls
{
	char					**argv;

	char					*flags;
	char					*flist;
	char					**paths;
	char					**files;

	int						i;
	int						y;
	int						x;
	int						dir_size;
	int						paths_size;

	int						totalbehavior;
	int						init;
	int						namemax;
	int						linemax;
	int						linkmax;
	int						ownermax;
	int						groupmax;
	int						minormax;
	int						majormax;
	int						bytesmax;
	int						nbblocks;
	int						blocksmax;
}							t_ls;

void						sort(t_ls *s, char *path, char **tab);
void						ft_ls(t_ls *s, char *path);
void						get_flags(t_ls *s);
void						get_paths(t_ls *s, int argc);
void						place_flags(t_ls *s, char *arg);
void						putlnames(t_ls *s, int i, char **dir, char *path);
void						get_devstats(t_ls *s, char *path, char **tab,
		int i);
void						init_l(t_ls *s);
char						*get_pwuid(struct stat *st);
char						*get_grgid(struct stat *st);
void						get_dev(t_ls *s, int st_rdev);
struct stat					*get_stats(char *path, char *name);
int							ft_abs(long long sec);
void						putdate(time_t atime);
void						putrights(int st_mode);
void						checkmax(t_ls *s, struct stat *st, char *owner,
		char *group);
void						putnbns(int str, int n, int a);
void						putpaths(t_ls *s, char **tab);
void						putns(char *str, int n, int a);
void						get_color(char *path, char *str);
void						print_error(char *path);
void						usage(char c);
void						putdir(t_ls *s, char *path);
void						puttotal(t_ls *s);
void						putsymlink(int st_mode, char *path, char *name);

#endif
