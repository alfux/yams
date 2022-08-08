/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:48:07 by alfux             #+#    #+#             */
/*   Updated: 2022/08/08 17:39:40 by alfux            ###   ########.fr       */
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

static int	ft_init_players(int ac, char **av, t_ply **ply)
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

static void	*ft_free_comb(char **cmb)
{
	int	i;

	i = 0;
	while (i < NBC)
	{
		if (*(cmb + i))
			free(*(cmb + i));
		i++;
	}
	free(cmb);
	return ((void *)0);
}

static char	**ft_init_comb(void)
{
	char	**cmb;
	int		i;

	cmb = ft_calloc(NBC, sizeof (char *));
	if (!cmb)
		return ((char **)0);
	*(cmb + ONE) = ft_strdup("one");
	*(cmb + TWO) = ft_strdup("two");
	*(cmb + THR) = ft_strdup("three");
	*(cmb + FOU) = ft_strdup("four");
	*(cmb + FIV) = ft_strdup("five");
	*(cmb + SIX) = ft_strdup("six");
	*(cmb + BRE) = ft_strdup("brelan");
	*(cmb + LIT) = ft_strdup("small straight");
	*(cmb + BIG) = ft_strdup("big straight");
	*(cmb + FUL) = ft_strdup("full");
	*(cmb + SQU) = ft_strdup("square");
	*(cmb + YAM) = ft_strdup("yam");
	*(cmb + LUC) = ft_strdup("luck");
	i = 0;
	while (i < NBC)
		if (!*(cmb + i++))
			return (ft_free_comb(cmb));
	return (cmb);
}

int	main(int ac, char **av)
{
	t_ply	*players;
	char	**combinations;

	if (ft_init_players(ac, av, &players))
		return (1);
	combinations = ft_init_comb();
	if (!combinations)
		return (ft_errmsg(2, players));
	if (ft_yams(players, combinations) && !ft_free_comb(combinations))
		return (ft_errmsg(2, players));
	ft_winner(players);
	ft_free_comb(combinations);
	free(players);
	return (0);
}
