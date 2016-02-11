/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:58:57 by pcarre            #+#    #+#             */
/*   Updated: 2016/02/11 18:53:10 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnc.h"

int		nbr_line(int *fd, char *file, t_max *max)
{
	int		i;
	char	nb_lines[15];
	char	buf;

	i = 0;
	buf = 0;
	if ((*fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while (read(*fd, &buf, 1) != 0)
	{
		nb_lines[i++] = buf;
		if (buf == '\n')
			break ;
	}
	max->charwrite = nb_lines[i--];
	max->charfull = nb_lines[i--];
	max->charempty = nb_lines[i--];
	nb_lines[i] = '\0';
	return (ft_atoi(nb_lines));
}

int		nbr_col(char *file)
{
	int		fd;
	char	tmp;
	int		i;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while (read(fd, &tmp, 1) > 0 && tmp != '\n')
	{
	}
	while (read(fd, &tmp, 1) > 0 && tmp != '\n')
		i = i + 1;
	if ((close(fd)) == -1)
		return (-1);
	else
		return (i);
}
