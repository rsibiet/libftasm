/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 15:18:16 by lchenut           #+#    #+#             */
/*   Updated: 2017/05/25 16:55:46 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <strings.h>
#define BUFF_SIZE 4096

void	ft_bzero(void *s, size_t n);
void	ft_test_bzero(int *tab);
char	*ft_strcat(char *s1, const char *s2);
void	ft_test_strcat(int *tab);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
int		ft_isalnum(int i);
int		ft_isascii(int i);
int		ft_isprint(int i);
int		ft_toupper(int i);
int		ft_tolower(int i);
void	ft_test_issmthg(int *tab, int (*test)(int), int (*real)(int), char *s);
int		ft_puts(const char *s);
void	ft_test_puts(int *tab);

size_t	ft_strlen(char *s);
void	ft_test_strlen(int *tab);
void	*ft_memset(void *b, int c, size_t len);
void	ft_test_memset(int *tab);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_test_memcpy(int *tab);
char	*ft_strdup(const char *str);
void	ft_test_strdup(int *tab);

void	ft_cat(int fd);
void	ft_test_cat(int *tab);

//void	main_bonus(int *tab);
//void	*ft_memchr(const void *s, int c, size_t n);
//void	ft_test_memchr(int *tab);
char	*ft_strchr(const char *s, int c);
//char	*ft_strrchr(const char *s, int c);
void	ft_test_chr(int *tab, char *(*ft)(const char *, int),
		char *(*str)(const char *, int), int i);
//int		ft_memcmp(const void *s1, const void *s2, size_t n);
//void	ft_test_memcmp(int *tab);
//int		ft_strcmp(const char *s1, const char *s2);
//void	ft_test_strcmp(int *tab);
//char	*ft_strstr(const char *s1, const char *s2);
//void	ft_test_strstr(int *tab);
//int		ft_isspace(int i);
//long	ft_atol(char *s);
//void	ft_test_atol(int *tab);
//int		ft_atoi(char *s);
//void	ft_test_atoi(int *tab);
//char	*ft_ltoa(long i);
//void	ft_test_ltoa(int *tab);
//char	*ft_itoa(int i);
//void	ft_test_itoa(int *tab);
//char	*ft_strndup(char *str, size_t n);
//void	ft_test_strndup(int *tab);
int tab[4] = {0, 0, 0, 0};


int		get_next_line(int fd, char **line);
typedef struct		s_gnl
{
	int				size;
	int				index;
	int				fd;
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

int		main()
{
	printf("\033[4;36m\t\tPART 1\n\033[0m");
	ft_test_bzero(tab);
	ft_test_strcat(tab);
	ft_test_issmthg(tab, &ft_isalpha, &isalpha, "isalpha");
	ft_test_issmthg(tab, &ft_isdigit, &isdigit, "isdigit");
	ft_test_issmthg(tab, &ft_isalnum, &isalnum, "isalnum");
	ft_test_issmthg(tab, &ft_isascii, &isascii, "isascii");
	ft_test_issmthg(tab, &ft_isprint, &isprint, "isprint");
	ft_test_issmthg(tab, &ft_toupper, &toupper, "toupper");
	ft_test_issmthg(tab, &ft_tolower, &tolower, "tolower");
	ft_test_puts(tab);
	printf("\033[4;36m\n\t\tPART 2\n\033[0m");
	ft_test_strlen(tab);
	ft_test_memset(tab);
	ft_test_memcpy(tab);
	ft_test_strdup(tab);
	printf("\033[4;36m\n\t\tPART 3\033[0m      \n");
	ft_test_cat(tab);
	printf("\033[4;36m\n\t\tBONUS!\033[0m\n");
	ft_test_chr(tab, &ft_strchr, &strchr, 0);
	printf("\033[1;32m\n%i/%i test suites passed. %i/%i tests passed.\033[0m",
			tab[1], tab[3], tab[0], tab[2]);
	if (tab[0] == tab[2])
		printf("  \360\237\215\273\n");
	else
		printf("\n");
	exit(0);
//	main_bonus(tab);
	return (0);
}

//void	main_bonus(int *tab)
//{
//	ft_test_memchr(tab);
//	ft_test_chr(tab, &ft_strrchr, &strrchr, 1);
//	ft_test_memcmp(tab);
//	ft_test_strcmp(tab);
//	ft_test_strstr(tab);
//	ft_test_issmthg(tab, &ft_isspace, &isspace, "isspace");
//	ft_test_atol(tab);
//	ft_test_atoi(tab);
//	ft_test_ltoa(tab);
//	ft_test_itoa(tab);
//	ft_test_strndup(tab);
//}

void	ft_test_bzero(int *tab)
{
	int i = tab[0] + 3;
	char	*real;
	char	*test;

	printf("\033[1;34mTest bzero    -> \033[0m");
	real = strdup("Hello World!"), test = strdup("Hello World!");
	bzero(real, 13);
	ft_bzero(test, 13);
	(!memcmp(real, test, 13)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[31mX\033[0m");
	free(real), free(test);
	real = strdup("Hello World!"), test = strdup("Hello World!");
	bzero(real, 3);
	ft_bzero(test, 3);
	(!memcmp(real, test, 13)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[31mX\033[0m");
	free(real), free(test);
	real = strdup("Hello World!"), test = strdup("Hello World!");
	bzero(real, 0);
	ft_bzero(test, 0);
	(!memcmp(real, test, 13)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[31mX\033[0m");
	free(real), free(test);
	tab[2] = tab[2] + 3;
	tab[3]++;
	if (i == tab[0])
		tab[1]++;
	printf("\n");
}

void	ft_test_strcat(int *tab)
{
	int i = tab[0] + 3;
	char	*test;
	char	*test2;

	if (!(test = (char *)malloc(sizeof(char) * 9)))
		return ;
	printf("\033[1;34mTest strcat   -> \033[0m");
	bzero(test, 9);
	ft_strcat(test, "");
	ft_strcat(test, "Bo");
	ft_strcat(test, "n");
	ft_strcat(test, "jou");
	ft_strcat(test, "");
	ft_strcat(test, "r.");
	ft_strcat(test, "");
	(!strcmp(test, "Bonjour.")) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test == ft_strcat(test, "")) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	free(test);
	if (!(test = (char *)malloc(sizeof(char) * 100)))
		return ;
	if (!(test2 = (char *)malloc(sizeof(char) * 100)))
		return ;
	test[99] = '\0';
	test2[99] = '\0';
	memset(test, 'A', 99);
	memset(test2, 'A', 99);
	test[10] = '\0';
	test2[10] = '\0';
	(!strcmp(ft_strcat(test, "Bonjour") + 18, strcat(test2, "Bonjour") + 18))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	free(test);
	free(test2);
	tab[2] = tab[2] + 3;
	tab[3]++;
	if (i == tab[0])
		tab[1]++;
	printf("\n");
}

void	ft_test_issmthg(int *tab, int (*test)(int), int (*real)(int), char *s)
{
	int i = tab[0] + 18;
	printf("\033[1;34mTest %s  -> \033[0m", s);
	(test('a') == real('a')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('a'+256) == real('a'+256)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('2') == real('2')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('Z') == real('Z')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('t') == real('t')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('0') == real('0')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('1') == real('1')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test(9999) == real(9999)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('1') == real('1')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('2') == real('2')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('A') == real('A')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test(' ') == real(' ')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('%') == real('%')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('\t') == real('\t')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('\n') == real('\n')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('\v') == real('\v')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test('\b') == real('\b')) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(test(7) == real(7)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	tab[2] = tab[2] + 18;
	tab[3]++;
	if (i == tab[0])
		tab[1]++;
	printf("\n");
}

void	ft_test_puts(int *tab)
{
	int i = tab[0] + 6;
	int out;
	int p[2];
	char *s;
	char *str;

	write(1, "\033[1;34mTest puts     -> \033[0m", 28);
	if (!(str = (char *)malloc(sizeof(char) * 10 * 1000)))
		return ;
	memset(str, '0', 10 * 1000);
	str[(10 * 1000) - 1] = '\0';
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_puts("Bonjour les amis");
	ft_puts("ca roule ?");
	ft_puts("");
	ft_puts(NULL);
	ft_puts(str);
	dup2(out, 1);
	close(p[1]);
	close(out);
	get_next_line(p[0], &s);
	(!strcmp(s, "Bonjour les amis"))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	free(s);
	get_next_line(p[0], &s);
	(!strcmp(s, "ca roule ?"))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	free(s);
	get_next_line(p[0], &s);
	(!strcmp(s, ""))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	free(s);
	get_next_line(p[0], &s);
	(!strcmp(s, "(null)"))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	free(s);
	get_next_line(p[0], &s);
	(!strcmp(s, str))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	free(s);
	out = get_next_line(p[0], &s);
	(!out) ? printf("\033[1;32m.\033[0m"), tab[0]++
		: printf("\033[1;31mX\033[0m");
	free(s);
	close(p[0]);
	tab[2] = tab[2] + 6;
	tab[3]++;
	if (i == tab[0])
		tab[1]++;
	printf("\n");
}

void	ft_test_strlen(int *tab)
{
	int i = tab[0] + 4;
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * 10 * 1000 * 1000)))
		return ;
	printf("\033[1;34mTest strlen   -> \033[0m");
	memset(s, '0', 10 * 1000 * 1000);
	s[(10 * 1000 * 1000) - 1] = '\0';
	(ft_strlen("aaa") == strlen("aaa")) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(ft_strlen("") == strlen("")) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(ft_strlen("aaa\0aaa") == strlen("aaa\0aaa")) ? printf("\033[1;32m.\033[0m"),
		tab[0]++ : printf("\033[1;31mX\033[0m");
	(ft_strlen(s) == strlen(s)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	free(s);
	tab[2] = tab[2] + 4;
	tab[3]++;
	if (i == tab[0])
		tab[1]++;
	printf("\n");
}

void	ft_test_memset(int *tab)
{
	int i = tab[0] + 5;
	char *s1, *s2;

	if (!(s1 = (char *)malloc(sizeof(char) * 10 * 1000)))
		return ;
	if (!(s2 = (char *)malloc(sizeof(char) * 10 * 1000)))
		return ;
	printf("\033[1;34mTest memset   -> \033[0m");
	memset(s1, '0', 10 * 1000), ft_memset(s2, '0', 10 * 1000);
	(!memcmp(s1, s2, 10 * 1000)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	free(s1), free(s2);
	s1 = strdup("abcdef"), s2 = strdup("abcdef");
	memset(s1, 0, 3), ft_memset(s2, 0, 3);
	(!memcmp(s1, s2, 7)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	free(s1), free(s2);
	s1 = strdup("abcdef"), s2 = strdup("abcdef");
	memset(s1, 1000, 7), ft_memset(s2, 1000, 7);
	(!memcmp(s1, s2, 7)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(ft_memset(s1, '1', 0) == s1) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(ft_memset(s1, '1', 5) == s1) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	free(s1), free(s2);
	tab[2] = tab[2] + 5;
	tab[3]++;
	if (i == tab[0])
		tab[1]++;
	printf("\n");
}

void	ft_test_memcpy(int *tab)
{
	int i = tab[0] + 5;
	char	test1[100], test2[100];
	char	real1[100], real2[100];

	printf("\033[1;34mTest memcpy   -> \033[0m");
	memset(test1, 33, 100), memset(test2, 63, 100);
	memset(real1, 33, 100), memset(real2, 63, 100);
	ft_memcpy(test1, test2, 50), memcpy(real1, real2, 50);
	(!memcmp(test1, real1, 100)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	ft_memcpy(test1, "Bonjour", 8), memcpy(real1, "Bonjour", 8);
	(!memcmp(test1, real1, 100)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	ft_memcpy(test1, test2, 100);
	(!memcmp(test1, test2, 100)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(ft_memcpy(test1, test2, 0) == test1) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(ft_memcpy(test1, test2, 50) == test1) ?
		printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	tab[2] = tab[2] + 5;
	tab[3]++;
	if (i == tab[0])
		tab[1]++;
	printf("\n");
}

void	ft_test_strdup(int *tab)
{
	int i = tab[0] + 7;
	char *s1, *s2;

	s1 = strdup("Hello world.... Again !\n"), s2 = ft_strdup(s1);
	printf("\033[1;34mTest strdup   -> \033[0m");
	(s1 != s2) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(!strcmp(s1, s2)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	free(s1), free(s2);
	s1 = strdup(""), s2 = ft_strdup(s1);
	(s1 != s2) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(!strcmp(s1, s2)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	free(s1), free(s2);
	s1 = strdup("Hello\n"), s2 = ft_strdup("Hello\n");
	(!strcmp(s1, s2)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	free(s1), free(s2);
	if (!(s2 = (char *)malloc(sizeof(char) * 10 * 1000)))
		return ;
	memset(s2, '0', 10 * 1000);
	s2[(10 * 1000) - 1] = '\0';
	s1 = ft_strdup(s2);
	(s1 != s2) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	(!strcmp(s1, s2)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	free(s1), free(s2);
	tab[2] = tab[2] + 7;
	tab[3]++;
	if (i == tab[0])
		tab[1]++;
	printf("\n");
}

void	ft_test_cat(int *tab)
{
	int i = tab[0] + 5;
	int fd;
	char *str;
	char *s1;
	char *rm[4] = {"/bin/rm", "-rf", "tmp_cat", NULL};
	int out, p[2];

	write(1, "\033[1;34mTest cat      -> \033[0m", 28);
	if (!(str = (char *)malloc(sizeof(char) * (10 * 1000 + 1))))
		return ;
	memset(str, '0', 10 * 1000);
	str[10 * 1000] = '\0';
	fd = open("tmp_cat", O_CREAT | O_WRONLY, 0644);
	dprintf(fd, "%s\n", str);
	dprintf(fd, "Salut les enfants\n");
	dprintf(fd, "\n");
	dprintf(fd, "ca roule les coupains ?\n");
	close(fd);
	usleep(5000);
	fd = open("tmp_cat", O_RDONLY);
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_cat(fd);
	dup2(out, 1);
	close(p[1]);
	close(out);
	get_next_line(p[0], &s1);
	(!strcmp(s1, str)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	free(s1);
	get_next_line(p[0], &s1);
	(!memcmp(s1, "Salut les enfants", 18))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	free(s1);
	get_next_line(p[0], &s1);
	(!strcmp(s1, "")) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	free(s1);
	get_next_line(p[0], &s1);
	(!memcmp(s1, "ca roule les coupains ?", 24))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	free(s1);
	(!get_next_line(p[0], &s1)) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
		printf("\033[1;31mX\033[0m");
	close(p[0]);
	free(s1);
	free(str);
	close(fd);
	ft_cat(42);
	ft_cat(-42);
	fd = open("Makefile", O_WRONLY);
	ft_cat(fd);
	close(fd);
	if (fork())
	{
		execve("/bin/rm", rm, NULL);
		exit(0);
	}
	else
		wait(NULL);
	tab[2] = tab[2] + 5;
	tab[3]++;
	if (i == tab[0])
		tab[1]++;
	printf("\n");
}
//
//void	ft_test_memchr(int *tab)
//{
//	int i = tab[0] + 5;
//
//	printf("\033[1;34mTest memchr   -> \033[0m");
//	(!memcmp(ft_memchr("abcdef", 'a', 5), memchr("abcdef", 'a', 5), 7))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!memcmp(ft_memchr("abcdef", 'c', 5), memchr("abcdef", 'c', 5), 5))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!memcmp(ft_memchr("abcdef", '\0', 7), memchr("abcdef", '\0', 7), 1))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!ft_memchr("abcdef", 'z', 6))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!ft_memchr("abcdef", 999, 6))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	tab[2] = tab[2] + 5;
//	tab[3]++;
//	if (i == tab[0])
//		tab[1]++;
//	printf("\n");
//
//}
//
void	ft_test_chr(int *tab, char *(*ft)(const char *, int),
		char *(*str)(const char *, int), int j)
{
	int i = tab[0] + 5;

	printf("%p\n", strchr("Yo !", '\0'));
	printf("COUCOU\n");
		printf("\033[1;34mTest strchr   -> \033[0m");
		printf("\033[1;34mTest strrchr  -> \033[0m");
	printf("COUCOU\n");
	(!strcmp(ft("abcdefa", 'a'), str("abcdefa", 'a')))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	printf("\n");
	(!strcmp(ft("abcdefedcba", 'c'), str("abcdefedcba", 'c')))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	printf("\n");
	(!strcmp(ft("abcdef", '\0'), str("abcdef", '\0')))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	printf("\n");
	(!ft("zabcdef\0z" + 1, 'z'))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	printf("\n");
	(!ft("abcdef", 999))
		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
	printf("\n");
	tab[2] = tab[2] + 5;
	tab[3]++;
	if (i == tab[0])
		tab[1]++;
}
//
//void	ft_test_memcmp(int *tab)
//{
//	int i = tab[0] + 7;
//
//	printf("\033[1;34mTest memcmp   -> \033[0m");
//	(ft_memcmp("ab\0ab", "ab\0ab", 5) == 0)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(ft_memcmp("ab\0ab", "abcab", 5) < 0)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(ft_memcmp("aab", "aaa", 4) > 0)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(ft_memcmp("aac", "aab", 2) == 0)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(ft_memcmp("bpp", "aww", 0) == 0)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(ft_memcmp("\200", "\0", 1) > 0)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(ft_memcmp("Bonjour !\n", "Bonjour !", 10) > 0)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	tab[2] = tab[2] + 7;
//	tab[3]++;
//	if (i == tab[0])
//		tab[1]++;
//	printf("\n");
//}
//
//void	ft_test_strcmp(int *tab)
//{
//	int i = tab[0] + 5;
//
//	printf("\033[1;34mTest strcmp   -> \033[0m");
//	(ft_strcmp("", "") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
//		printf("\033[1;31mX\033[0m");
//	(ft_strcmp("abc", "abc") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
//		printf("\033[1;31mX\033[0m");
//	(ft_strcmp("abc", "abd") < 0) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
//		printf("\033[1;31mX\033[0m");
//	(ft_strcmp("\200", "\0") > 0) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
//		printf("\033[1;31mX\033[0m");
//	(ft_strcmp("a", "abcde") < 0) ? printf("\033[1;32m.\033[0m"), tab[0]++ :
//		printf("\033[1;31mX\033[0m");
//	tab[2] = tab[2] + 5;
//	tab[3]++;
//	if (i == tab[0])
//		tab[1]++;
//	printf("\n");
//}
//
//void	ft_test_strstr(int *tab)
//{
//	int i = tab[0] + 10;
//	char buf[] = "Ce test est une theiere.";
//	char buf2[] = "ozarabozaraboze";
//
//	printf("\033[1;34mTest strstr   -> \033[0m");
//	(!strcmp(strstr(buf, "une"), ft_strstr(buf, "une")))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!strcmp(strstr(buf, "C"), ft_strstr(buf, "C")))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!strcmp(strstr(buf, "."), ft_strstr(buf, ".")))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!strcmp(strstr(buf, ""), ft_strstr(buf, "")))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!ft_strstr(buf, "aaaaa"))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!strcmp(strstr(buf2, "ozaraboze"), ft_strstr(buf2, "ozaraboze")))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!ft_strstr(buf, "BWRAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!strcmp(strstr("", ""), ft_strstr("", "")))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(!strcmp(strstr(buf, "une"), ft_strstr(buf, "une")))
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	char *s = ft_strstr(buf, "C");
//	(buf == s) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	tab[2] = tab[2] + 10;
//	tab[3]++;
//	if (i == tab[0])
//		tab[1]++;
//	printf("\n");
//}
//
//void	ft_test_atol(int *tab)
//{
//	int i = tab[0] + 31;
//
//	printf("\033[1;34mTest atol     -> \033[0m");
//	(ft_atol(" -sfecf") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("+2798") == 2798) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("+0089") == 89) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("a56") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("       --s8") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("0001020304") == 1020304) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("000000000000000110") == 110) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("-153") == -153) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("+132") == 132) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("++876") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("--132") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("dwbk ") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol(" 1") == 1) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("42jk ") == 42) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol(" 21") == 21) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("     32 ") == 32) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("\n         42 24") == 42) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("1-2") == 1) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("4+2") == 4) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("   +442") == 442) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("   -4232") == -4232) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("+") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("-") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("-+1") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("\200123") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("123\200") == 123) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("  \t\n  \r\r\v\f-889") == -889) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atol("-9223372036854775807") == -9223372036854775807)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(ft_atol("9223372036854775807") == 9223372036854775807)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(ft_atol("0") == 0)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	tab[2] = tab[2] + 31;
//	tab[3]++;
//	if (i == tab[0])
//		tab[1]++;
//	printf("\n");
//}
//
//void	ft_test_atoi(int *tab)
//{
//	int i = tab[0] + 31;
//
//	printf("\033[1;34mTest atoi     -> \033[0m");
//	(ft_atoi(" -sfecf") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("+2798") == 2798) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("+0089") == 89) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("a56") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("       --s8") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("0001020304") == 1020304) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("000000000000000110") == 110) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("-153") == -153) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("+132") == 132) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("++876") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("--132") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("dwbk ") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi(" 1") == 1) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("42jk ") == 42) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi(" 21") == 21) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("     32 ") == 32) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("\n         42 24") == 42) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("1-2") == 1) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("4+2") == 4) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("   +442") == 442) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("   -4232") == -4232) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("+") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("-") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("-+1") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("\200123") == 0) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("123\200") == 123) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("  \t\n  \r\r\v\f-889") == -889) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	(ft_atoi("-2147483648") == -2147483648)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(ft_atoi("2147483647") == 2147483647)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	(ft_atoi("0") == 0)
//		? printf("\033[1;32m.\033[0m"), tab[0]++ : printf("\033[1;31mX\033[0m");
//	tab[2] = tab[2] + 31;
//	tab[3]++;
//	if (i == tab[0])
//		tab[1]++;
//	printf("\n");
//}
//
//void	ft_test_ltoa(int *tab)
//{
//	int i = tab[0] + 5;
//	char *s;
//
//	printf("\033[1;34mTest ltoa     -> \033[0m");
//	s = ft_ltoa(0);
//	(!strcmp(s, "0")) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s);
//	s = ft_ltoa(1234567890);
//	(!strcmp(s, "1234567890")) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s);
//	s = ft_ltoa(-9876543210);
//	(!strcmp(s, "-9876543210")) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s);
//	s = ft_ltoa(-9223372036854775807);
//	(!strcmp(s, "-9223372036854775807")) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s);
//	s = ft_ltoa(42);
//	(!strcmp(s, "42")) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s);
//	tab[2] = tab[2] + 5;
//	tab[3]++;
//	if (i == tab[0])
//		tab[1]++;
//	printf("\n");
//}
//
//void	ft_test_itoa(int *tab)
//{
//	int i = tab[0] + 5;
//	char *s;
//
//	printf("\033[1;34mTest itoa     -> \033[0m");
//	s = ft_itoa(0);
//	(!strcmp(s, "0")) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s);
//	s = ft_itoa(1234567890);
//	(!strcmp(s, "1234567890")) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s);
//	s = ft_itoa(-987654321);
//	(!strcmp(s, "-987654321")) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s);
//	s = ft_itoa(-2147483648);
//	(!strcmp(s, "-2147483648")) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s);
//	s = ft_itoa(42);
//	(!strcmp(s, "42")) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s);
//	tab[2] = tab[2] + 5;
//	tab[3]++;
//	if (i == tab[0])
//		tab[1]++;
//	printf("\n");
//}
//
//void	ft_test_strndup(int *tab)
//{
//	int i = tab[0] + 6;
//	char *s, *s2;
//
//	printf("\033[1;34mTest strndup  -> \033[0m");
//	s = ft_strndup("Bonjour", 4), s2 = strndup("Bonjour", 1);
//	(!strcmp(s, "Bonj")) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s), free(s2);
//	s = ft_strndup("Bonjour", 15), s2 = strndup("Bonjour", 15);
//	(!strcmp(s, s2)) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s), free(s2);
//	s = ft_strndup("Bonjour", 7), s2 = strndup("Bonjour", 7);
//	(!strcmp(s, s2)) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s), free(s2);
//	s = ft_strndup("Bonjour", 0), s2 = strndup("Bonjour", 0);
//	(!strcmp(s, s2)) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s), free(s2);
//	s = ft_strndup("Bon\0jour", 10), s2 = strndup("Bon\0jour", 10);
//	(!strcmp(s, s2)) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s), free(s2);
//	s = ft_strndup("Bonjour\0Salut", 999), s2 = strndup("Bonjour\0Salut", 999);
//	(!strcmp(s, s2)) ? printf("\033[1;32m.\033[0m"), tab[0]++
//		: printf("\033[1;31mX\033[0m");
//	free(s), free(s2);
//	tab[2] = tab[2] + 6;
//	tab[3]++;
//	if (i == tab[0])
//		tab[1]++;
//	printf("\n");
//}


/*
 ** Annexe:
 */

static t_gnl	*gnl_init_struct(int fd)
{
	int		size;
	t_gnl	*gnl;

	if (!(gnl = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	if (!(gnl->str = (char *)malloc(sizeof(char) * BUFF_SIZE)))
	{
		free(gnl);
		return (NULL);
	}
	if ((size = read(fd, gnl->str, BUFF_SIZE)) < 0)
	{
		free(gnl->str);
		free(gnl);
		return (NULL);
	}
	gnl->index = 0;
	gnl->size = size;
	gnl->fd = fd;
	gnl->next = NULL;
	return (gnl);
}

int				gnl_cnt_end_line(t_gnl *gnl, int fd)
{
	int		index;
	int		size;
	t_gnl	*tmp;

	size = 0;
	index = gnl->index;
	while (index < gnl->size && gnl->str[index] != '\n')
	{
		index++;
		size++;
		if (index == gnl->size && gnl->size == BUFF_SIZE)
		{
			if (!(tmp = gnl_init_struct(fd)))
				return (-1);
			tmp->next = gnl->next;
			gnl->next = tmp;
			gnl = gnl->next;
			index = 0;
		}
	}
	return (size);
}

static t_gnl	*gnl_destroy(t_gnl **begin, t_gnl **tmp)
{
	if (tmp[1])
		tmp[1]->next = tmp[0]->next;
	else
		*begin = tmp[0]->next;
	free(tmp[0]->str);
	tmp[0]->str = NULL;
	free(tmp[0]);
	tmp[0] = NULL;
	if (tmp[1])
		return (tmp[1]->next);
	return (*begin);
}

int				gnl_print(t_gnl **begin, t_gnl **tmp, int size, char **line)
{
	int i;

	if (size < 0 || !(*line = (char *)malloc(sizeof(char) * (size + 1))))
		return (-1);
	i = 0;
	while (size > 0)
	{
		(*line)[i++] = (tmp[0]->str[tmp[0]->index++]);
		if (tmp[0]->index == tmp[0]->size)
			tmp[0] = gnl_destroy(begin, tmp);
		size--;
	}
	(*line)[i] = '\0';
	if (!tmp[0] || (tmp[0]->index == tmp[0]->size && tmp[0]->size < BUFF_SIZE))
	{
		if (tmp[0])
			gnl_destroy(begin, tmp);
		return (0);
	}
	tmp[0]->index = tmp[0]->index + 1;
	if (tmp[0]->index == tmp[0]->size)
		tmp[0] = gnl_destroy(begin, tmp);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*begin = NULL;
	t_gnl			*tmp[2];
	int				size;

	if (!line)
		return (-1);
	if (!begin)
	{
		if (!(begin = gnl_init_struct(fd)))
			return (-1);
	}
	tmp[0] = begin;
	tmp[1] = NULL;
	while (tmp[0]->fd != fd)
	{
		if (!(tmp[0]->next))
		{
			if (!(tmp[0]->next = gnl_init_struct(fd)))
				return (-1);
		}
		tmp[1] = tmp[0];
		tmp[0] = tmp[0]->next;
	}
	size = gnl_cnt_end_line(tmp[0], fd);
	return (gnl_print(&begin, tmp, size, line));
}
