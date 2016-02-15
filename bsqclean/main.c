/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:01:09 by pcarre            #+#    #+#             */
/*   Updated: 2016/02/12 11:44:48 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnc.h"

int		minimum(unsigned int a, unsigned int b, unsigned int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

int		bsq_check_line(char *tmp, unsigned int *ptr1, unsigned int *ptr2,
						t_max *max)
{
	static int		line;
	unsigned int	size_max;
	unsigned int	i;

	i = 1;
	((max->new)++ == 1) ? (line = 2) : (0);
	if ((first_char(tmp, ptr2, max, line)) == -1)
	{
		ft_putstr("error bsq_check_line if first_char\n");
		return (-1);
	}
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
		{
			ft_putstr("error bsq_check_line else if tmp[i] != max->charfull\n");
			return (-1);
		}
		++i;
	}
	++line;
	return (0);
}

int		bsq(int fd, int nb_line, int nb_col, t_max *max)
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
	{
		ft_putstr("error bsq if malloc fail\n");
		return (-1);
	}
	if (first_line(fd, ptr1, tmp, max) == -1)
	{
		ft_putstr("error bsq if first_line == -1\n");
		return (-1);
	}
	while (++i < nb_line)
	{
		if (read(fd, &tmp[0], nb_col + 1) != nb_col + 1)
		{
			ft_putstr("error bsq if read != nb_col + 1\n");
			return (-1);
		}
		if ((bsq_check_line(&tmp[0], ptr1, ptr2, max)) == -1)
		{
			ft_putstr("error bsq if bsq_check_line == -1\n");
			return (-1);
		}
		ft_swap(&ptr1, &ptr2);
	}
	if (read(fd, &tmp[0], nb_col + 1) > 0)
	{
		ft_putstr("error bsq if read > 0\n");
		return (-1);
	}
	free_ptr(&ptr1, &ptr2, &tmp);
	return (0);
}

int		init_bsq(char *file)
{
	int			nb_line;
	int			nb_col;
	t_max		max;
	int			fd;

	fd = 0;
	max.size = 0;
	max.new = 1;
	if ((nb_line = nbr_lines(file)) == -1)
	{
		ft_putstr("error init_bsq if nbr_line == -1\n");
		return (-1);
	}
	if ((nb_col = nbr_col(file)) == -1)
	{
		ft_putstr("error init_bsq if nbr_col == -1\n");
		return (-1);
	}
	if ((bsq(fd, nb_line, nb_col, &max)) == -1)
	{
		ft_putstr("error init_bsq if bsq == -1\n");
		close(fd);
		return (-1);
	}
	close(fd);      // habon ??
	fd = display(file, &max, nb_line, nb_col);
	init_chars(&fd, &max);
	return ((fd == -1) ? (-1) : (close(fd)));
}

int		main(int argc, char **argv)
{
	int		i;
	int		file_actual;
	char	*file;

	i = 1;
	file_actual = 1;
	if (argc == 1)
	{
		file = create_file();
		if ((init_bsq(file)) == -1)
		{
			ft_putstr("error main n1\n");
			write(2, "map error\n", 10);
		}
	}
	else if (argc > 1)
		while (file_actual <= argc - 1)
		{
			if ((init_bsq(argv[i++])) == -1)
			{
				ft_putstr("error main n2\n");
				write(2, "map error\n", 10);
				return (0);
			}
			if (file_actual++ < argc - 1)
				write(1, "\n", 1);
		}
	return (0);
}
