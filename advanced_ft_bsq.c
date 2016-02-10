/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_ft_bsq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-elh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/27 15:05:37 by hben-elh          #+#    #+#             */
/*   Updated: 2015/08/27 22:51:29 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools_bsq.h"

int		ft_store_std_input(void)
{
	int		fd;
	char	buffer;

	fd = open("bsq_map.txt", O_CREAT | O_TRUNC | O_RDWR, 0700);
	if (fd == -1)
	{
		write(2, "Dat is an error.\n", 17);
		return (-1);
	}
	else
	{
		while (read(0, &buffer, 1) != 0)
			write(fd, &buffer, 1);
	}
	return (fd);
}

void	ft_bsq_qualidad_check(int fd)
{
	int		ccases;
	char	head[14];
	char	buffer;
	char	symb[3];

	ccases = 0;
	if (fd != 0)
	{
		while (read(fd, &buffer, 1) != 0)
		{
			head[ccases++] = buffer;
			if (buffer == '\n')
				break ;
		}
		symb[0] = head[ccases--];
		symb[1] = head[ccases--];
		symb[2] = head[ccases--];
		while (ccases >= 0)
		{
			if ((head[ccases] <= '0') && (head[ccases] >= '0'))
				ccases--;
			else
				ft_putstr("Error : bad map size.");
		}
	}
}
