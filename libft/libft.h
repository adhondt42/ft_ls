/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:42:10 by jtaibi            #+#    #+#             */
/*   Updated: 2018/04/24 15:38:00 by adhondt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/fcntl.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <time.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*before;
}					t_list;

typedef struct		s_dir
{
	char			*path;
	char			*name;
	char			type;
	int				time;
	int				nlink;
	int				rdev;
	int				uid;
	int				gid;
	char			*mode;

	struct stat		*stats;
	struct s_dir	*next;
	struct s_dir	*before;
}					t_dir;

void				ft_free2tab(char **tab, char **tab2);
void				free3(void *f1, void *f2, void *f3);
void				puttab(char **tab, char *end);
char				*ft_strjoin_f(char const *s1, char const *s2, int j);
char				*createpath(char *path, char *name);
struct stat			*get_lstats(char *path, char *name);
size_t				tablen(char **src);
void				ft_swapptr(char **ptr, char **ptr2);
void				sorttab_rev(char **tab);
void				sorttab_ascii(char **tab);
void				ft_puttab(char **tab, char *end);
char				**ft_initializetab(size_t size);
char				**addtotab_f(char **tab, char *str, size_t i);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *fnew);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_swaplst(t_list *lst1, t_list *lst2);
void				ft_freelst1(t_list **lst);
void				ft_color(char *str, char *color);
void				ft_swapchar(char *c1, char *c2);
void				ft_swapint(int *i1, int *i2);
void				ft_swapstr(char *s1, char *s2);
void				ft_erno(char *path);
void				ft_put2str(char **tab);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl(const char *s);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putsstr(char *str);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putnstr(const char *str, size_t n);
void				ft_putlstr(const char *str);
void				ft_putnoctet(void *str, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_freetab(char **str);

int					ft_lendir(char *path, int err, int cache);
int					ft_isdir(char *path);
char				**ft_readdir(char *path, int a);
void				ft_swapdir(t_dir *d1, t_dir *d2);
t_dir				*ft_reversedir(t_dir **dir);

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *tab, const char *teub, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_atoi(const char *nptr);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strslen(char *str, char *s);
int					ft_isintab(char *s, char c);
int					ft_index(const char *str, char c);
int					ft_rindex(char *str, char c);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(char const *str);
size_t				ft_tablen(char **tab);
size_t				ft_strclen(const char *str, char c);
char				ft_ftype(int st_mode);
char				*ft_strlower(char *str);
char				*ft_strcut(char *str, int index, int len);
char				*ft_strccut(char *str, int index, char c);
char				*ft_strrev(const char *str);
char				*ft_strcpyc(const char *str, char c);
char				*ft_strccpy(const char *str, char c);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strdup(const char *src);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strfjoin(char *s1, char *s2, int free);
char				*ft_strnjoin(char const *s1, char const *s2, size_t n);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big,
								const char *little, size_t len);
char				**ft_strsplit(char const *s, char c);
int					ft_intlen(int nb);
#endif
