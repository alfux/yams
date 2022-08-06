/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:30:09 by alfux             #+#    #+#             */
/*   Updated: 2022/08/06 23:48:28 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "yams.h"

static int	ft_equality(t_ply *oth, t_ply *win)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while ((oth + ++i)->name)
		if ((oth + i)->score == win->score && ft_strncmp(win->name,
				(oth + i)->name, ft_strlen(win->name) + 1))
			ret++;
	if (ret)
		ft_printf("%sWinners are %s", YELLOW, win->name);
	i = -1;
	while (ret && (oth + ++i)->name)
	{
		if ((oth + i)->score == win->score && ft_strncmp(win->name,
				(oth + i)->name, ft_strlen(win->name) + 1))
		{
			ret--;
			if (ret)
				ft_printf(", %s", (oth + i)->name);
			else
				return (ft_printf(" and %s! ", (oth + i)->name));
		}
	}
	return (0);
}

void	ft_winner(t_ply *ply)
{
	int	i;
	int	j;
	int	mx;

	i = -1;
	mx = 0;
	while ((ply + ++i)->name)
		(ply + i)->score = ft_total((ply + i)->grd);
	i = -1;
	while ((ply + ++i)->name)
	{
		if ((ply + i)->score > mx)
		{
			mx = (ply + i)->score;
			j = i;
		}
	}
	if (!ft_equality(ply, ply + j))
		ft_printf("%sWinner is %s! ", YELLOW, (ply + j)->name);
	ft_printf("Congrats !%s\n", WHITE);
}
