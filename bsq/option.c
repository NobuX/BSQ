/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 14:37:55 by mlegeay           #+#    #+#             */
/*   Updated: 2016/02/12 15:35:57 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fnc.h"

int	nbr_line(int *fd, char *file, t_max *max)
{
	int		i;
	char	nb_lines[15];
	char	buf;

	i = 0;
	buf = 0;
	if ((*fd = open(file, O_RDONLY)) == -1)
		return (bad_file());
	while (read(*fd, &buf, 1) > 0 && buf != '\n')
			nb_lines[i++] = buf;
	max->charempty = nb_lines[i - 3];
	max->charfull = nb_lines[i - 2];
	max->charwrite = nb_lines[i - 1];
	nb_lines[i - 3] = 0;
	return (ft_atoi(nb_lines));
}

int	nbr_col(char *file)
{
	int		fd;
	char	tmp;
	int		i;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (bad_file());
	while (read(fd, &tmp, 1) > 0 && tmp != '\n')
	{
	}
	while (read(fd, &tmp, 1) > 0 && tmp != '\n')
		i = i + 1;
	if ((close(fd)) == -1)
	{
		ft_putstr("error: could not close file\n");
		return (-1);
	}
	return (i);
}

int	go_first_line(char *file, int *fd)
{
	char	tmp;
	int		i;

	i = 0;
	tmp = 0;
	if ((*fd = open(file, O_RDONLY)) == -1)
		return (bad_file());
	while (read(*fd, &tmp, 1) > 0 && tmp != '\n')
	{
	}
	tmp = 0;
	while (read(*fd, &tmp, 1) > 0 && tmp != '\n')
		i = i + 1;
	if ((close(*fd)) == -1)
	{
		ft_putstr("error: could not close file\n");
		return (-1);
	}
	if ((*fd = open(file, O_RDONLY)) == -1)
		return (bad_file());
	tmp = 0;
	while (read(*fd, &tmp, 1) > 0 && tmp != '\n')
	{
	}
	return (i);
}

int	get_nb_file(int argc)
{
	int	i;
	int	nb_files;

	i = 1;
	nb_files = 0;
	while (i < argc)
	{
		i = i + 1;
		nb_files = nb_files + 1;
	}
	return (nb_files);
}
