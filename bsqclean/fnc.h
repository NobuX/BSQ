/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 13:15:02 by mlegeay           #+#    #+#             */
/*   Updated: 2016/02/11 18:51:34 by pcarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FNC_H
# define FNC_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_max
{
	int			x_max;
	int			y_max;
	int			size;
	int			new;
	char		charempty;
	char		charfull;
	char		charwrite;
}				t_max;

/*	fnc.c		*/
void			ft_swap(unsigned int **ptr1, unsigned int **ptr2);
int				save_max(t_max *max, int i, int line, int current);
int				ft_atoi(char *str);
int				first_line(int fd, unsigned int *first, char *tmp, t_max *max);
int				first_car(char *tmp, unsigned int *ptr2, t_max *max, int line);

/*	option.c	*/
int				nbr_line(int *fd, char *file, t_max *max);
int				nbr_col(char *file);

/*	display.c	*/
void			free_ptr(unsigned int **ptr1, unsigned int **ptr2, char **tmp);
char			*create_file(void);
int				display(char *file, t_max *max, int nb_lines, int nb_cols);

#endif
