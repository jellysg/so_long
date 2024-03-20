/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:28:42 by jergoh            #+#    #+#             */
/*   Updated: 2024/03/04 00:58:42 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>

// linked list type
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

// linked list functions
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_lstsize(t_list *lst);

// char functions
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

// memory functions
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// conversion functions
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

// file descriptor functions
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// character string functions
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// ft_printf functions
size_t	ft_putaddress(void *addr);
size_t	ft_putchar(const char c);
size_t	ft_puthex_l(const unsigned int hex);
size_t	ft_puthex_u(const unsigned int hex);
size_t	ft_putnbr(const int n);
size_t	ft_putstr(const char *str);
size_t	ft_putunbr(const unsigned int un);
int		ft_printf(const char *str, ...);

// gnl functions
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

t_list	*ft_lstlast(t_list *lst);
t_list	*remove_last_element(t_list **lst);
char	*remove_last_element_extra(t_list *last, int i);
char	*get_next_line(int fd);
char	*get_next_line_no_free(int fd);
int		ft_strlen(const char *str);
bool	found_newline(t_list *list);
void	free_list(t_list *list);
void	append_buffer_to_list(t_list **list, char *buffer, int num_bytes);
void	prepare_line(char **line, t_list *list);

#endif
