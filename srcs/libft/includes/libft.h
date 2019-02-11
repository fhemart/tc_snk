/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:11:45 by jbulant           #+#    #+#             */
/*   Updated: 2018/10/17 02:55:01 by fhemart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/types.h>

# define FAILURE		-1
# define SUCCESS		0

# define ST_FAILURE		-1
# define ST_SUCCESS		0
# define ST_CONTINUE	1

# define FT_STDEL		-1
# define FT_STGET		+0
# define FT_STSET		+1

typedef unsigned char	t_byte;

typedef enum		e_sys
{
	WALK_OK = 0,
	WALK_NAMETOOLONG,
	WALK_BADIO,
}					t_sys;

typedef int			t_bool;

# ifndef TRUE
#  define TRUE	1
# endif
# ifndef FALSE
#  define FALSE	0
# endif

/*
**	INDEXES:
**		_FT_LST_
**		_FT_STR_
**		_FT_MEM_
**		_FT_PMATCH_
**		_FT_CONVERT_
**		_FT_PUT_
**		_FT_IS_
**		_FT_MATH_
**		_FT_UNICODE_
*/

/*
**	_FT_LST_
*/

typedef struct s_list	t_list;

struct			s_list
{
	t_list	*next;
	void	*content;
	size_t	content_size;
};

char			*ft_nlst2str(t_list *lst, size_t n);
char			*ft_lst2str(t_list *lst);
t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void **));
void			ft_lstdel(t_list **alst, void (*del)(void **));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstappend(t_list **alst, t_list *new);
void			ft_lstjoin(t_list **alst, t_list *new);
void			ft_lstsort(t_list **head, int (*cmp)());
void			ft_lst_isort(t_list **head, t_list *toadd
						, int (*cmp)(t_list*, t_list*));
void			ft_lstprint(t_list *lst);
void			ft_lstrprint(t_list *lst);
void			ft_lstprint_content(t_list *lst);
t_list			*ft_lstfromarray(char **ar);
t_list			*ft_lstdup(t_list *dup);
size_t			ft_lstheight(t_list *lst);

/*
**	_FT_STR_
*/

size_t			ft_astrlen(char **astr, size_t alen);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strndup(const char *src, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcasecmp(const char *s1, const char *s2);
int				ft_strncasecmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strrealloc(char **dst, size_t new_size);
void			ft_strdel(char **as);
void			ft_arstrdel(char ***ar);
void			ft_strclr(char *str);
void			ft_striter(char *str, void (*f)(char *));
void			ft_striteri(char *str, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *str, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
t_bool			ft_strequ(const char *s1, const char *s2);
t_bool			ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *str, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoin_proper(char **s1, char *s2);
char			*ft_strtrim(const char *str);
char			**ft_strsplit(const char *str, char c);
char			**ft_arstrnew(size_t size);
size_t			ft_count_words(const char *str, char seperator);
size_t			ft_strclen(const char *str, char c);
char			*ft_strrev(char *str);
t_list			*ft_strsplit_lst(char *str, char delim);

/*
**	_FT_MEM_
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memdup(const void *src, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memclr(void *buffer, size_t size);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_swap(int *a, int *b);
void			ft_swap_addr(void **ap1, void **ap2);
t_byte			ft_swap_byte(const t_byte byte);

/*
**	_FT_PMATCH_
*/

typedef union u_chrmsk	t_chrmsk;

union			u_chrmsk
{
	int		pattern[4];
};

t_chrmsk		new_chrmsk(char *pattern);
void			ft_chrmskadd(t_chrmsk *target, char *add);
void			ft_chrmskrm(t_chrmsk *msk, char *todel);
t_bool			char_match_pattern(char c, t_chrmsk *cp);
char			*chrmsk_getnext_match(char *src, t_chrmsk *tomatch);
char			**ft_create_wordtab(char *str, t_chrmsk delim);
/*
**	_FT_CONVERT_
*/
# define LOWER_HEXDECSTR	"0123456789abcdef"

typedef unsigned long long	t_ull;

int				ft_atoi(const char *str);
int				ft_atoi_base(char *str, char *base);
int				ft_atoi_movefw(char **line);
long			ft_atol(const char *str);
long long		ft_atoll(const char *str);
t_ull			ft_atoull(const char *str);
long long		ft_strtoll(const char *str, int *errcode);
int				ft_hdtoi(int hexadecimal);
int				ft_strhextoi(char *str, int max_len, int *parsed_len);
char			*ft_itoa(int n);
char			*ft_static_itoa(int nb);
char			*ft_itoa_base(int nb, char *base);
int				ft_toupper(int c);
int				ft_tolower(int c);
t_bool			ft_basecheck(char *base);
int				ft_get_basevalue(char value, char *base, int b_height);
t_byte			ft_hexstr_to_byte(char *str);
int				ft_chr2index(char *str, char c);

/*
**	_FT_PUT_
*/

int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putendl(char *str);
int				ft_putnbr(int nb);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *str, int fd);
int				ft_putendl_fd(char *str, int fd);
int				ft_putnbr_fd(int nb, int fd);
int				ft_print_byte(const t_byte byte);
int				ft_putarendl(char **arstr);

/*
**	_FT_IS_
*/

t_bool			ft_strisspace(char *str);
t_bool			ft_isoctal(char c);
t_bool			ft_islower(char c);
t_bool			ft_isalpha(int c);
t_bool			ft_isdigit(int c);
t_bool			ft_isalnum(int c);
t_bool			ft_isascii(int c);
t_bool			ft_isprint(int c);
t_bool			ft_isspace(int c);
t_bool			ft_iswhitespace(int c);
t_bool			ft_ishexdec(char c);
t_bool			ft_str_iscolorhex(char *str);
t_bool			ft_strisdigit(const char *str);
t_bool			ft_strisnumeric(const char *str);

/*
**	_FT_MATH_
*/

int				ft_abs(int nb);
int				ft_npow(int n, int pow);
unsigned int	ft_poweroftwo(int n);
int				ft_poweroften(int n);

/*
**	_FT_GNL_
*/

# define BUFF_SIZE		1
# define LF				'\n'

typedef struct s_fd_lst	t_fd_lst;

struct			s_fd_lst
{
	int			fd;
	char		*line;
	t_fd_lst	*next;
};

int				get_next_line(const int fd, char **line);

/*
**	_FT_UNICODE_
*/

# define UNIBYTE1	0x80
# define UNIBYTE2	0xc0
# define UNIBYTE3	0xe0
# define UNIBYTE4	0xf0

# define MASK1		0x3f
# define MASK2		0x1f
# define MASK3		0xf
# define MASK4		0x7

typedef struct s_unicode	t_unicode;

struct			s_unicode
{
	int		c;
	int		size;
};

t_unicode		convert_unicode(int uc);
t_unicode		hex_to_unicode(char *hptr, char **endptr, int size);

/*
**	_FLOL_
*/

char			*ft_sys_getenvinfo(char **env, char *key);
char			*ft_strchrend(const char *s, int c);
unsigned long	ft_hash_joaat(char *key, size_t len);
int				ft_putchar2(int c);
t_chrmsk		ft_msk_new_chrmsk(char *str);
t_bool			ft_msk_char_match_pattern(char c, t_chrmsk *chrmsk);
int				ft_browse_dir(char *dname, int (*fptr)(), void *data,\
								void *(*fnewcontent)());

#endif
