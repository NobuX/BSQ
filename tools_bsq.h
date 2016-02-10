/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bsq.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/25 11:01:46 by pcarre            #+#    #+#             */
/*   Updated: 2015/08/27 17:03:08 by hben-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_BSQ_H
# define TOOLS_BSQ_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

void	ft_putchar(char c);

void	ft_putstr(char *str);

void	ft_putnbr(int n);

int		ft_store_std_input(void);

void	ft_bsq_qualidad_check(int fd);

int		ft_read(void);

#endif
