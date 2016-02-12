/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <pcarre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:58:57 by pcarre            #+#    #+#             */
/*   Updated: 2016/02/12 11:42:18 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnc.h"

void	init_chars(int *fd, t_max *max)
{
	/* on devrait garder cette fonction uniquement pour initialiser les marqueurs de cases */
	int		i;
	char	nb_lines[15];
	char	buf;

	i = 0;
	buf = 0;
	while (read(*fd, &buf, 1) != 0)
	{
		nb_lines[i++] = buf;
		if (buf == '\n')
			break ;
	}
	max->charwrite = nb_lines[i - 1];
	max->charfull = nb_lines[i - 2];
	max->charempty = nb_lines[i - 3];
	/* a partir de la ca renvoi le nombre de lignes theoriquement demandees par les parametres de la carte, mais pas un 
	 * decompte du nombre reel de lignes donc jpense ca va pas, et faudrait retourner 0 puis faire une fonction qui verifie
	 * le nombre de ligne ou colonnes reel */
/*	i = i - 3;
	nb_lines[i] = '\0';
	return (ft_atoi(nb_lines)); */
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
		;
	while (read(fd, &tmp, 1) > 0 && tmp != '\n')
		i = i + 1;
	if (close(fd) == -1)
		return (-1);
	else
		return (i);
}

int		nbr_lines(char *file)
{
	int		fd;
	char	tmp;
	int		i;

	i = 0;
   if ((fd = open(file, O_RDONLY)) == 1)
	   return (-1);
   while (read(fd, &tmp, 1) > 0 && tmp != '\n')
	   ;
   while (read(fd, &tmp, 1))
	   if (tmp == '\n')
		   i++;
   if (close(fd) == -1)
	   return (-1);
   return (i);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}
