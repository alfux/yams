/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:48:07 by alfux             #+#    #+#             */
/*   Updated: 2022/08/04 09:30:01 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "yams.h"

static int	ft_errmsg(int errn)
{
	if (errn == 1)
		ft_putstr_fd("\033[31mError: Syntax-> nb name1 name2 ...\033[0m\n", 2);
	else if (errn == 2)
		ft_putstr_fd(
			"\033[31mError: First arg must be a positiv integer\033[0m\n", 2);
	else if (errn == 3)
		ft_putstr_fd("\033[31mError: You need at least one player\033[0m\n", 2);
	else
		ft_putstr_fd("\033[31mError: Unknown\033[0m\n", 2);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (ft_errmsg(1));
	if (!ft_chkarg(av))
		return (ft_errmsg(2));
	if (ac < 3)
		return (ft_errmsg(3));
	return (0);
}
