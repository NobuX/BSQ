/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 18:36:53 by pcarre            #+#    #+#             */
/*   Updated: 2016/02/11 18:42:51 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnc.h"

void	ft_swap(unsigned int **a, unsigned int **b)
{
	unsigned int	tmp;

	tmp = **a;
	**a = **b;
	**b = tmp;
}

int		save_max(t_max *max, int i, int line, int current)
{
	max->size = current;
	max->x_max = i + 1;
	max->y_max = line;
	return (current);
}

int		ft_atoi(char *str)
{
	int		i;
	int		negativ;
	int		nbr;

	i = 0;
	negativ = 0;
	nbr = 0;
	if (str[i] == 45)
		negativ = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nbr = nbr * 10;
		nbr = nbr + ((int)str[i] - 48);
		i++;
	}
	if (negativ == 1)
		return (-nbr);
	else
		return (nbr);
}

int		first_line(int fd, unsigned int *first, char *tmp, t_max *max)
{
	int		i;
	int		size_max;

	i = 0;
	size_max = max->size;
	while (read(fd, &tmp[i], 1) > 0 && tmp[i] != '\n')
	{
		first[i] = 0;
		if (tmp[i] == max->charempty)
		{
			first[i] = 1;
			if (size_max <= 0)
				size_max = save_max(max, i, 1, 1);
		}
		else if (tmp[i] != max->charfull)
			return (-1);
		i = i + 1;
	}
	if (tmp[i] == 0)
		return (-1);
	return (0);
}

int		first_car(char *tmp, unsigned int *ptr2, t_max *max, int line)
{
	ptr2[0] = 0;
	if (tmp[0] == max->charempty)
		ptr2[0] = 1;
	else if (tmp[0] != max->charfull && tmp[0] != '\n')
		return (-1);
	if (max->size <= 0 && ptr2[0] == 1)
		max->size = save_max(max, 0, line, ptr2[0]);
	return (0);
}
