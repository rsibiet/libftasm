/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:03:45 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/25 11:03:46 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libfts.h"
#include <string.h>
#include <fcntl.h>
#include <ctype.h>

void	ft_putstr(char const *s)
{
	write(1, (void *)s, ft_strlen(s));
}

int main(void)
{
	int			i;
	int			j;
	int 		ret;
	int 		tmp;

	i = 0;
	char	*s;
	printf("\n--------PART 1-------\n\n");
	printf("test de ft_bzero:\n");
	s = (char *)malloc(sizeof(char) * 6);
	s[0] = 'h';
	s[1] = 'e';
	s[2] = 'l';
	s[3] = 'l';
	s[4] = 'o';
	printf("BEFORE BZERO: %s%%\n", s);
	ft_bzero(s, sizeof(s));
	printf("AFTER BZERO: %s%%\n", s);
		i = 0;
	while (i < 5)
	{
		if (s[i] == 0)
			printf("s[%d] = 0, ", i);
		i++;
	}
	free(s);
	printf("\n\ntest de ft_strcat:\n");
	s = (char *)malloc(sizeof(char) * 8);
	s[0] = 't';
	s[1] = 'e';
	s[2] = '\0';
	char	*ptr;
	ptr = ft_strcat(s, "st123");
	printf("te + st123 = %s\n", ptr);
	free(s);
	s = (char *)malloc(sizeof(char) * 8);
	s[0] = 0;
	ptr = ft_strcat(s, "test");
	printf("NULL + test = %s\n", ptr);
	ptr = ft_strcat(s, "123");

	printf("test + 123 = %s\n\n", ptr);

	printf("test de ft_puts:\n");
	ft_putstr("ft_puts(NULL): ");
	ft_puts(NULL);
	j = ft_puts("ecrit par ft_puts");
	if (j > 0)
		printf("return value of ft_puts: nonnegative integer\n\n");
	else
		printf("return value of ft_puts: negative integer\n\n");
	j = -9;
	tmp = 0;
	ret = 0;
	printf("full tests de ft_isalpha, ft_isdigit, ft_isalnum, \n");
	printf("ft_isascii, ft_isprint, ft_tolower, ft_toupper\n");
	while (j < 255)
	{
		if (ft_isalpha(j) != isalpha(j))
			ret = 1;
		if (ft_isdigit(j) != isdigit(j))
			ret = 1;
		if (ft_isalnum(j) != isalnum(j))
			ret = 1;
		if (ft_isascii(j) != isascii(j))
			ret = 1;
		if (ft_isprint(j) != isprint(j))
			ret = 1;
		if (ft_tolower(j) != tolower(j))
			ret = 1;
		if (ft_toupper(j) != toupper(j))
			ret = 1;
		if (ret != 0)
		{
			tmp++;
			printf("ERREUR!\n");
		}
		ret = 0;
		j++;
	}
	if(tmp == 0)
		printf("SUCCESS !\n\n");
	printf("--------PART 2-------\n\n");
	printf("test de ft_strlen:\n");
	printf("len de '123456789012345':%zu\n\n", ft_strlen("123456789012345"));

	s = ft_strdup("Je suis une copie");


	int n = 0;
	printf("test de ft_strdup: %s\n\n", s);
	int		win;
	char	test[] = "12345";
	char	test6[] = "je SUI un tests OK ASMOLALA";

	i = 0;
	win = 0;
	ft_memset(test, 'y', 5);
	ft_memset(test6, '>', 26);
	while (i < 5)
	{
		if (test[i] != 'y' && (win = 1))
			printf("\033[1;31merror %c pour %d\033[0m\n", test[i], i);
		i++;
	}
	i = 0;
	while (i < 26 )
	{
		if (test6[i] != '>' && (win = 2))
			printf("\033[1;31merror %c pour %d\033[0m\n", test6[i], i);
		i++;
	}
	i = 0;
	if (win == 0)
		printf("ft_memset OK\033[0m\n\n");
	if (win & 1)
		printf("test ONE KO\033[0m\n\n");
	if (win & 2)
		printf("test TWO KO\033[0m\n\n");

	printf("test de ft_memset{s, 's', 5): %s\n", ptr);
	s = (char *)malloc(sizeof(char) * 8);
	printf("\ntest de ft_memcpy(s, 'test123', 5): %s\n\n",
		ft_memcpy(s, "test123", 5));
	free(s);
	s = ft_memalloc(6);




	printf("\n--------BONUS-------- %s\n", s);
	printf("\ntest de ft_memalloc(6): %s%%\n", s);
		i = 0;
	while (i < 6)
	{
		if (s[i] == 0)
			printf("s[%d] = 0, ", i);
		i++;
	}
	printf("\n\ntest de ft_strnlen('test', 3): %zu\n", ft_strnlen("test", 3));
	printf("test de ft_strnlen('coucou', 42): %zu\n",
		ft_strnlen("coucou", 42));
	free(s);
	s = (char *)malloc(sizeof(char) * 30);
	s[0] = 0;
	printf("\ntest de ft_strncat(s, 'coucou', 42): %s\n",
		ft_strncat(s, "coucou", 42));
	printf("test de ft_strncat(s, 'foobar', 3): %s\n",
		ft_strncat(s, "foobar", 3));
	printf("\ntest de ft_strchr(s, 'e'): %s\n", ft_strchr(s, 'e'));	
	printf("test de ft_strchr(s, '\\0'): %s\n", ft_strchr(s, '\0'));	
	printf("test de ft_strchr(s, 'f'): %s\n", ft_strchr(s, 'f'));	
	free(s);
	printf("\ntest de ft_abs(0): %d\n", ft_abs(0));	
	printf("test de ft_abs(-42): %d\n", ft_abs(-42));	
	printf("test de ft_abs(1): %d\n", ft_abs(1));	
	printf("test de ft_abs(-1): %d\n", ft_abs(-1));	
	printf("\ntest de ft_putchar('X'):\n");
	ft_putchar('X');
	printf("\ntest de ft_putchar(65):\n");
	ft_putchar(65);
	ft_putchar('\n');
	return (0);
}
