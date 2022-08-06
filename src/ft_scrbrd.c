/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrbrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:55:02 by alfux             #+#    #+#             */
/*   Updated: 2022/08/06 07:36:25 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "yams.h"

static int	ft_maxsze(t_ply *ply)
{
	int	size;
	int	ret;
	int	i;

	size = 0;
	ret = 0;
	i = 0;
	while ((ply + i)->name)
	{
		size = ft_strlen((ply + i++)->name);
		if (size > ret)
			ret = size;
	}
	return (ret);
}

static void	ft_pntlne(t_ply *ply, int mx)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(ply->name);
	ft_printf("%s| %s%s", GREEN, RED, ply->name);
	while (i++ <= mx - size)
		ft_printf(" ");
	i = 0;
	while (i < NBC)
	{
		if (ply->grd[i] == (t_grd)(-1))
			ft_printf("%s|    ", GREEN, RED, ply->grd[i++]);
		else
			ft_printf("%s| %s%2i ", GREEN, RED, ply->grd[i++]);
	}
	ft_printf("%s| %s%3i", GREEN, RED, ft_total(ply->grd));
	ft_printf("%s|%s\n", GREEN, WHITE);
}

static void	ft_fstlne(int mx, char **cmb)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("%s/", GREEN);
	while (i++ < mx + 2)
		ft_printf("-");
	i = -1;
	while (++i < 13)
	{
		j = 0;
		ft_printf("|");
		while (j < 3)
			ft_printf("%c", *(*(cmb + i) + j++) - 32);
		ft_printf(" ");
	}
	ft_printf("|TOT ");
	ft_printf("\\%s\n", WHITE);
}

static void	ft_lstlne(int mx)
{
	int	i;

	i = 0;
	ft_printf("%s\\", GREEN);
	while (i++ < mx + 72)
		ft_printf("-");
	ft_printf("/%s\n", WHITE);
}

int	ft_scrbrd(t_ply *ply, char **cmb, int onlyone)
{
	int	i;
	int	mx;

	i = 0;
	mx = ft_maxsze(ply);
	ft_fstlne(mx, cmb);
	if (onlyone != -1)
		ft_pntlne(ply + onlyone, mx);
	else
		while ((ply + i)->name)
			ft_pntlne(ply + i++, mx);
	ft_lstlne(mx);
	return (0);
}
