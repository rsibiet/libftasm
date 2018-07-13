/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:13:15 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/19 14:13:17 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H
# include <string.h>

void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strcat(char *s1, const char *s2);
size_t	ft_strlen(const char *s);
int		ft_puts(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *scr, size_t n);
char	*ft_strdup(const char *s1);
void	ft_cat(int fd);
void	*ft_memalloc(size_t size);
size_t	ft_strnlen(const char *s, size_t maxlen);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_abs(int i);
void	ft_putchar(char c);

#endif
