/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 13:55:59 by mlegeay           #+#    #+#             */
/*   Updated: 2016/02/12 14:42:43 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fnc.h"

int	first_line(int fd, unsigned int *first, char *tmp, t_max *max)
{
	int	i;
	int	size_max;

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
			return (bad_caractere());
		i = i + 1;
	}
	if (tmp[i] == 0)
		return (bad_line_len());
	return (0);
}

int	first_car(char *tmp, unsigned int *ptr2, t_max *max, int line)
{
	ptr2[0] = 0;
	if (tmp[0] == max->charempty)
		ptr2[0] = 1;
	else if (tmp[0] != max->charfull && tmp[0] != '\n')
		return (bad_caractere());
	if (max->size <= 0 && ptr2[0] == 1)
		max->size = save_max(max, 0, line, ptr2[0]);
	return (0);
}

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
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
	int i;
	int negativ;
	int nbr;

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
