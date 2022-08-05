/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:33:05 by alfux             #+#    #+#             */
/*   Updated: 2022/08/04 23:32:15 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "yams.h"

static int	ft_largest_name(t_ply *ply)
{
	int	i;
	int	size;
	int	ret;

	i = 0;
	size = 0;
	ret = 0;
	while ((ply + i)->name)
	{
		size = ft_strlen((ply + i++)->name);
		if (!size)
			return (0);
		if (size > ret)
			ret = size;
	}
	if (ret > 66)
		ret = 0;
	return (ret);
}

static void	ft_print_line(t_ply *ply, int i, int msize)
{
	int	size;

	ft_printf("%s|%s Player %2i: ", GREEN, YELLOW, i + 1);
	size = ft_strlen((ply + i)->name);
	ft_printf("%s", (ply + i)->name, (ply + i)->score);
	while (msize - size++)
		ft_printf(" ");
	ft_printf(" %3i%s|%s\n", (ply + i)->score, GREEN, WHITE);
}

static void	ft_last_line(int msize)
{
	int	i;

	ft_printf("%s\\", GREEN);
	i = 0;
	while (++i < 17 + msize)
		ft_printf("-");
	ft_printf("/%s\n", WHITE);
}

static void	ft_first_line(int msize)
{
	int	i;

	ft_printf("%s/", GREEN);
	i = 0;
	while (++i < ((17 + msize) / 2) - 2)
		ft_printf("-");
	ft_printf("YAMS");
	i += 3;
	while (++i < 17 + msize)
		ft_printf("-");
	ft_printf("\\%s\n", WHITE);
}

int	ft_print_players(t_ply *ply)
{
	int	msize;
	int	i;

	msize = ft_largest_name(ply);
	if (!msize)
		return (1);
	ft_first_line(msize);
	i = 0;
	while ((ply + i)->name)
		ft_print_line(ply, i++, msize);
	ft_last_line(msize);
	return (0);
}
