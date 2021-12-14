/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:25:29 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/14 17:11:26 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# define BOOL int
# define TRUE 1
# define FALSE 0

# define DOFREE 1
# define DONTFREE 0

typedef struct s_dynamic_array
{
	void	**arr;
	int		size;
	int		max;
}					t_vector;

typedef struct s_garbage_collector
{
	t_vector	collec;
	t_vector	cleaner;
}					t_gc;

typedef struct s_list
{
	int				x;
	int				y;
	struct s_list	*next;
}					t_list;

typedef struct s_list2
{
	int				nb;
	int				index;
	int				group;
	struct s_list2	*prev;
	struct s_list2	*next;
}					t_list2;

int					valeur_absolue(int nb);
BOOL				optimized_msleep(unsigned int ms);

/*
 ******************   BYTEWISE & MEMORY  ******************
*/

void				*ft_calloc(size_t nb, size_t size);
void				init_zero(void *pt, size_t i);
void				*mem_set(void *dest, int c, size_t size);
void				*mem_copy(void *dest, const void *src, size_t size);

/*
 *******************  IS? FONCTIONS  *******************
*/

int					is_double_signed(long double doub);
int					is_not_number(long double doub);
int					is_infinite(long double doub);
int					is_whitespace(char c);
int					is_only_numeric(char *s);

/*
 *******************  CHAR & STRING  *******************
*/

char				*substr(char *s, size_t start, size_t len);
char				*substr_free(char *s, size_t start, size_t len,
						BOOL freestr);
char				*strjoin(char *s1, char *s2);
char				*strjoin_free(char *s1, char *s2,
						BOOL freestr1, BOOL freestr2);
size_t				string_len(const char *s);
char				**string_split(const char *str, char c);
int					shift_right_add(char *str, char c, int i);
int					shift_left_erase(char *str, int i, int dist);
int					str_n_comp(char *str, char *str2, int stop);
char				*str_nstr_comp(char *str1, char *str2, size_t size_str2);
char				*string_duplicate(const char *original, int size);
char				*string_chr(const char *str, char c);

/*
 *******************  CHAR ARRAY   *******************
*/

void				array_clear(void **array);
char				**arrstr_duplicate(char **tab, int size);
char				**arrstr_malloc(int size);

/*
 *******************  NB & STRING CONVERSION  *******************
*/

int					utoa_len(unsigned long long nb, int sizebase);
int					utoa_base(unsigned long long nb, char *dest,
						char *base, int sizebase);
int					itoa_base(long long nb, char *dest,
						char *base, int sizebase);
int					atoi_windex(const char *str, int *i);
int					my_atoi(const char *str);
long int			atoli_windex(const char *str, int *i);
long int			ft_atoli(const char *str);
double				atodoub_windex(const char *str, int *i);

/*
 *******************  PARSER  *******************
*/

BOOL				parser_atoui(const char *str, unsigned int *nb);

/*
 *******************  LINKED LIST  *******************
*/

t_list				*lst_new(int x, int y);
void				lst_addfront(t_list **alst, t_list *new);
void				lst_addback(t_list **alst, t_list *new, t_list *last);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstsecondlast(t_list *lst);
void				lst_clear(t_list **lst, void (*del)(void*));
t_list				*lst_duplicate(t_list *original);

/*
 *******************  LINKED LIST 2 *******************
*/

void				lst2_addfront(t_list2 **alst, t_list2 *new);
t_list2				*lst2_getlast(t_list2 *lst);
t_list2				*lst2_getsecondlast(t_list2 *lst, t_list2 *last);
void				lst2_addback(t_list2 **alst, t_list2 *new, t_list2 *last);
void				lst2_clear(t_list2 **lst, void (*del)(void*));
t_list2				*lst2_duplicate(t_list2 *original);

/*
 *******************  VECTOR DYNAMIC ARRAY  *******************
*/

t_vector			*vector_new(int size);
BOOL				vector_init(t_vector *v, int size);
BOOL				vector_add(t_vector *v, void *data);
BOOL				vector_extend(t_vector *v);
void				vector_purge(t_vector *v, void (*f)(void *));
void				vector_clean(t_vector *v, void (*f)(void *));

/*
 *******************  GARBAGE COLLECTOR  *******************
*/

t_gc				*gc_new(void);
BOOL				gc_init(t_gc *gc);
BOOL				gc_add(t_gc *gc, void *data, void (*f)(void *));
void				gc_purge(t_gc *gc);
void				gc_clean(t_gc *gc);

/*
 *******************  FILE DESCRIPTOR  *******************
*/

int					get_next_line(int fd, char **buffer,
						char **line, BOOL *eof);
char				*read_input(char *prompt, int size);

#endif
