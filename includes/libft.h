/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:25:29 by rsanchez          #+#    #+#             */
/*   Updated: 2021/12/20 14:15:04 by rsanchez         ###   ########.fr       */
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

// a struct for dynamicly allocate a bunch of pointer with a scalable size, with appropriate function to handle it.

// **arr is a pointer on array of pointers
// size is the actual size of the array
// max is the the maximum size authorize in a such list

typedef struct s_dynamic_array
{
	void	**arr;
	int		size;
	int		max;
}					t_vector;

// a struct for dynamicly allocate a string of scalable size, with appropriate function to handle it.

// *arr is a scalable and real time modifiable string
// size is the actual size of the string
// max is the the maximum size authorize in a such list

typedef struct s_dynamic_string
{
	char	*arr;
	int		size;
	int		max;
}					t_vecstr;

// a struct for stock a bunch of data *and* automaticly create an associate cleaning function stocked into the cleaner.

// collec is a vector which stock data
// cleaner is a vector which stock address of functions for cleaning theses data

typedef struct s_garbage_collector
{
	t_vector	collec;
	t_vector	cleaner;
}					t_gc;

// a simple definition of double int chain list

typedef struct s_list
{
	int				x;
	int				y;
	struct s_list	*next;
}					t_list;

// a simple definition of bidirectionnal chain list, able to go backward as foward as well

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

// ft_calloc use 2 parameter : size of an element and number of elements to malloc. It returns a pointer on an array of these element, initialized to 0

void				*ft_calloc(size_t nb, size_t size);
void				init_zero(void *pt, size_t i);
void				*mem_set(void *dest, int c, size_t size);
void				*mem_copy(void *dest, const void *src, size_t size);

/*
 *******************  IS? FONCTIONS  *******************
*/

// is_double_signed is used to find if a double is negativ or not
// is_infinite is a function to find if a double is infinite

int					is_double_signed(long double doub);
int					is_not_number(long double doub);
int					is_infinite(long double doub);
int					is_whitespace(char c);
int					is_only_numeric(char *s);

/*
 *******************  CHAR & STRING  *******************
*/

// functions preceded by "free" add the option to clean the origin string during the process

// shift_right_add and shift_left_erase are used for modify a string by adding or erasing a caracter inside.

char				*substr(char *s, size_t start, size_t len);
char				*substr_free(char *s, size_t start, size_t len,
						BOOL freestr);
char				*strjoin(char *s1, char *s2);
char				*strjoin_free(char *s1, char *s2,
						BOOL freestr1, BOOL freestr2);
size_t				string_len(const char *s);
char				**string_split(const char *str, char c);
int					shift_right_add(char *str, int i, char c);
int					shift_left_erase(char *str, int i, int dist);
int					str_n_comp(const char *str, const char *str2, int stop);
char				*str_nstr_comp(char *str1, char *str2, size_t size_str2);
char				*string_duplicate(const char *original, int size);
char				*string_chr(const char *str, char c);

/*
 *******************  CHAR ARRAY   *******************
*/

// arrstr_duplicate is used to duplicate an array of string
// arrstr_malloc is used for create an array of string of "size" -> obsolete
// array_clear is used for clear an array of pointers

void				array_clear(void **array);
char				**arrstr_duplicate(char **tab, int size);
char				**arrstr_malloc(int size);

/*
 *******************  NB & STRING CONVERSION  *******************
*/

// windex functions are obsolete
// ft_atoli is an atoi long int

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

// atoi for unsigned int which return a bolean for warn if there was a problem

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

// functions for using a bidirectional list

void				lst2_addfront(t_list2 **alst, t_list2 *new);
t_list2				*lst2_getlast(t_list2 *lst);
t_list2				*lst2_getsecondlast(t_list2 *lst, t_list2 *last);
void				lst2_addback(t_list2 **alst, t_list2 *new, t_list2 *last);
void				lst2_clear(t_list2 **lst, void (*del)(void*));
t_list2				*lst2_duplicate(t_list2 *original);

/*
 *******************  VECTOR DYNAMIC ARRAY  *******************
*/

// vector_purge free the content (arr variable) of a vector *and* every single pointer which it content

t_vector			*vector_new(int size);
BOOL				vector_init(t_vector *v, int size);
BOOL				vector_add(t_vector *v, void *data);
BOOL				vector_extend(t_vector *v);
void				*vector_get(t_vector *v, int i);
t_vector			*vector_extract(t_vector *v, int i);
void				vector_delone(t_vector *v, int i, void (*f)(void *));
int					vector_shift_down(t_vector *v, int i);
void				vector_flush(t_vector *v, void (*f)(void *));
void				vector_purge(t_vector *v, void (*f)(void *));
void				vector_empty_clear(t_vector *v);
void				vector_clear(t_vector *v, void (*f)(void *));
void				vector_arrstr_clean(t_vector *v);
	
/*
 *******************  VECTOR DYNAMIC STRING  *******************
*/

// vecstr_new will malloc and return a vecstr of the size asked
// vecstr_init will do the same thing, except that it takes into parameter the vector to assign, and return a BOOL to warn if something did wrong
// vecstr_extend take a vector in parameter, check if it can double the size (compare to maximum value), try to do so, and return a BOOL to warn if something did wrong
// vecstr_purge free the content (arr variable) of a vector
// vecstr_clean free the content by calling vectstr_purge AND free the vector itself
// vecstr_delone erase size caracters from the index i in the vector v, with no return
// vecstr_insert add a caracter c in the index i, and return a BOOL to warn if something did wrong

t_vecstr			*vecstr_new(int size);
BOOL				vecstr_init(t_vecstr *v, int size);
BOOL				vecstr_add(t_vecstr *v, char c);
BOOL				vecstr_extend(t_vecstr *v);
BOOL				vecstr_insert(t_vecstr *v, int i, char c);
BOOL				vecstr_concat(t_vecstr *dest, t_vecstr *src);
BOOL				vecstr_concat_purge(t_vecstr *dest,
						t_vecstr *src, BOOL dofree);
BOOL				vecstr_concat_clear(t_vecstr *dest,
						t_vecstr *src, BOOL dofree);
void				vecstr_delone(t_vecstr *v, int i, int size);
void				vecstr_flush(t_vecstr *v);
void				vecstr_purge(t_vecstr *v);
void				vecstr_clear(t_vecstr *v);

/*
 *******************  GARBAGE COLLECTOR  *******************
*/

//gc_new malloc and return a garbage collector which content two vectors, one for collec and one for gather pointers on cleaning fonctions
//gc_init do the same, but have to use a vector given in parameter. It returns a BOOL to warn if there was an issue, or not
//gc_add add a new element in the collec argument of the garbage collector and place the function given in parameter as the new used to 

t_gc				*gc_new(void);
BOOL				gc_init(t_gc *gc);
BOOL				gc_add(t_gc *gc, void *data, void (*f)());
void				gc_flush(t_gc *gc);
void				gc_purge(t_gc *gc);
void				gc_clean(t_gc *gc);

/*
 *******************  FILE DESCRIPTOR  *******************
*/

int					get_next_line(int fd, char **buffer,
						char **line, BOOL *eof);
char				*read_input(char *prompt, int size);

#endif
