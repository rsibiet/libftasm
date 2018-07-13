/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 11:03:52 by rsibiet           #+#    #+#             */
/*   Updated: 2017/05/25 11:03:53 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

void	ft_cat(int fd);

int		main(int ac, const char **av)
{
	ft_cat(0);
	ft_cat(open(__FILE__, O_RDONLY));
	ft_cat(open(av[0], O_RDONLY));
	ft_cat(-42);
	(void)ac;
	return (0);
}
