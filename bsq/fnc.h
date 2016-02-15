/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 13:15:02 by mlegeay           #+#    #+#             */
/*   Updated: 2016/02/12 15:34:49 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FNC_H
# define FNC_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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

char			*create_file(void);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
void			ft_puterror(char *str);
int				bad_file(void);
int				check_nb_lines(char *str);
int				bad_nb_line(void);
int				nbr_line(int *fd, char *file, t_max *max);
int				go_first_line(char *file, int *fd);
int				first_line(int fd, unsigned int *first, char *tmp, t_max *max);
void			ft_swap(unsigned int **ptr1, unsigned int **ptr2);
int				save_max(t_max *max, int i, int line, int current);
void			free_ptr(unsigned int **ptr1, unsigned int **ptr2, char **tmp);
int				bad_alloc(char *file);
int				bad_caractere(void);
int				bad_line_len(void);
int				ft_atoi(char *str);
int				display(char *file, t_max *max, int nb_lines, int nb_cols);
void			ft_putnbr(int nb);
int				nbr_col(char *file);
int				nbr_file(int argc, char **argv);
int				first_car(char *tmp, unsigned int *ptr2, t_max *max, int line);
int				get_nb_file(int nb);

#endif
