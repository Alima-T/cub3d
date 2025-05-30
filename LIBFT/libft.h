/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:26:24 by aokhapki          #+#    #+#             */
/*   Updated: 2025/05/27 18:34:36 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "gnl/get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//# mandatory_functions
int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
int					ft_isalnum(int ch);
int					ft_isascii(int ch);
int					ft_isprint(int ch);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *dest, size_t byte_n);
void				*ft_memcpy(void *dest, const void *src, size_t byte_n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t dest_size);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int symbol);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t byte_n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t byte_n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *src);

//additional_functions
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strjoin_con(char const *s1, char *connector,
						char const *s2);
char				*ft_strjoin_char(char *str, char c);
int					ft_isnum(const char *str);
size_t				ft_strcspn(const char *s, const char *reject);
char				*ft_strstr(const char *haystack, const char *needle);
// bonus_functions
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));

//gnl

char				*get_next_line(int fd);
#endif
