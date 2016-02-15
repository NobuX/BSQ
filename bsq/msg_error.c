/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegeay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/24 12:59:20 by mlegeay           #+#    #+#             */
/*   Updated: 2016/02/12 15:34:30 by mlegeay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fnc.h"
#include <unistd.h>

int	bad_file(void)
{
	ft_puterror("map error0\n");
	return (-1);
}

int	bad_line_len(void)
{
	ft_puterror("map error:\n");
	return (-1);
}

int	bad_caractere(void)
{
	ft_puterror("map error1\n");
	return (-1);
}

int	bad_nb_line(void)
{
	ft_puterror("map error2\n");
	return (-1);
}

int	map_empty(void)
{
	ft_puterror("map error3\n");
	return (-1);
}
