/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:48:07 by alfux             #+#    #+#             */
/*   Updated: 2022/08/04 15:21:10 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "yams.h"

static int	ft_errmsg(int errn, void *tofree)
{
	if (tofree)
		free(tofree);
	if (errn == 1)
		ft_putstr_fd("\033[31mSyntax: name1 name2 name3 ...\033[0m\n", 2);
	else if (errn == 2)
		ft_putstr_fd("\033[31mError: Memory allocation failed\033[0m\n", 2);
	else if (errn == 3)
		ft_putstr_fd("\033[31mError: Name too long or too short\033[0m\n", 2);
	else
		ft_putstr_fd("\033[31mError: Unknown\033[0m\n", 2);
	return (1);
}

static int	ft_init(int ac, char **av, t_ply **ply)
{
	if (ac < 2)
		return (ft_errmsg(1, (void *)0));
	*ply = ft_getprm(ac, av);
	if (!*ply)
		return (ft_errmsg(2, (void *)0));
	if (ft_print_players(*ply))
		return (ft_errmsg(3, *ply));
	return (0);
}

int	main(int ac, char **av)
{
	t_ply	*players;

	if (ft_init(ac, av, &players))
		return (1);
	free(players);
	return (0);
}
