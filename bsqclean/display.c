/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:52:33 by pcarre            #+#    #+#             */
/*   Updated: 2016/02/11 18:52:48 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnc.h"

void	free_ptr(unsigned int **ptr1, unsigned int **ptr2, char **tmp)
{
	if (*ptr1)
		free(*ptr1);
	if (*ptr2)
		free(*ptr2);
	if (*tmp)
		free(*tmp);
}

char	*create_file(void)
{
	int		fd;
	char	c;

	fd = open("map4", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	while (read(0, &c, 1))
	{
		write(fd, &c, 1);
	}
	close(fd);
	return ("map4");
}

void	print_s(char *tmp, t_max *max, int nbr_col)
{
	int		i;
	char	c;

	c = max->charwrite;
	i = 1;
	write(1, &tmp[0], max->x_max - max->size);
	write(1, "\033[33;40m", 9);
	while (i++ <= max->size)
		write(1, &c, 1);
	write(1, "\033[0m", 5);
	i = max->x_max;
	write(1, &tmp[i], nbr_col - i);
}

int		display(char *file, t_max *max, int nbr_line, int nbr_col)
{
	char	*tmp;
	int		fd;
	int		i;
	char	test;

	test = 0;
	i = 1;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	while (read(fd, &test, 1) > 0 && test != '\n')
		if ((tmp = (char*)malloc(sizeof(char) * (nbr_col + 1))) == NULL)
			return (-1);
	tmp[nbr_col++] = 0;
	while (i <= nbr_line)
	{
		if ((read(fd, tmp, nbr_col)) < 0)
			return (-1);
		if (i++ <= max->y_max - max->size || i - 1 > max->y_max)
			write(1, tmp, nbr_col);
		else
			print_s(tmp, max, nbr_col);
	}
	free(tmp);
	return (fd);
}
