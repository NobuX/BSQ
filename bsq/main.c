/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 13:14:43 by mlegeay           #+#    #+#             */
/*   Updated: 2016/02/12 15:33:53 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnc.h"

int	minimum(unsigned int a, unsigned int b,
		unsigned int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int	bsq_check_line(char *tmp, unsigned int *ptr1,
		unsigned int *ptr2, t_max *max)
{
	static int		line;
	unsigned int	size_max;
	unsigned int	i;

	i = 1;
	((max->new)++ == 1) ? (line = 2) : (0);
	if ((first_car(tmp, ptr2, max, line)) != 0)
		return (-1);
	size_max = max->size;
	while (tmp[i] != '\n')
	{
		ptr2[i] = 0;
		if (tmp[i] == max->charempty)
		{
			ptr2[i] = minimum(ptr2[i - 1], ptr1[i - 1], ptr1[i]) + 1;
			if (ptr2[i] > size_max)
				size_max = save_max(max, i, line, ptr2[i]);
		}
		else if (tmp[i] != max->charfull)
			return (bad_caractere());
		++i;
	}
	++line;
	return (0);
}

int	bsq(int fd, int nb_line, int nb_col, t_max *max)
{
	char			*tmp;
	unsigned int	*ptr1;
	unsigned int	*ptr2;
	int				i;

	i = 0;
	tmp = (char*)malloc(sizeof(char) * (nb_col + 2));
	ptr1 = (unsigned int*)malloc(sizeof(int) * (nb_col + 1));
	ptr2 = (unsigned int*)malloc(sizeof(int) * (nb_col + 1));
	if (tmp == NULL || ptr1 == NULL || ptr2 == NULL)
		return (bad_alloc("error"));
	if (first_line(fd, ptr1, tmp, max) == -1)
		return (-1);
	while (++i < nb_line)
	{
		if (read(fd, &tmp[0], nb_col + 1) != nb_col + 1)
			return (bad_line_len());
		if ((bsq_check_line(&tmp[0], ptr1, ptr2, max)) == -1)
			return (-1);
		ft_swap(&ptr1, &ptr2);
	}
	if (read(fd, &tmp[0], nb_col + 1) > 0)
		return (bad_nb_line());
	free_ptr(&ptr1, &ptr2, &tmp);
	return (0);
}

int	init_bsq(char *file)
{
	int			nb_line;
	int			nb_col;
	t_max		maximum;
	int			fd;

	maximum.size = 0;
	maximum.new = 1;
	if ((nb_line = nbr_line(&fd, file, &maximum)) == -1)
		return (-1);
	if ((nb_col = nbr_col(file)) == -1)
		return (-1);
	if ((bsq(fd, nb_line, nb_col, &maximum)) == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	fd = display(file, &maximum, nb_line, nb_col);
	return ((fd == -1) ? (-1) : (close(fd)));
}

int	main(int argc, char **argv)
{
	int		i;
	int		file_actual;
	int		nb_files;
	char	*file;

	i = 1;
	file_actual = 1;
	if (argc == 1)
	{
		file = create_file();
		if ((init_bsq(file)) == -1)
			return (-1);
	}
	else if (argc > 1)
	{
		nb_files = get_nb_file(argc);
		while (file_actual <= nb_files)
		{
			if ((init_bsq(argv[i++])) == -1)
				return (-1);
			if (file_actual++ < nb_files)
				ft_putstr("\n");
		}
	}
	return (0);
}
