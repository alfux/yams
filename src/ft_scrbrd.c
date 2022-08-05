/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrbrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:55:02 by alfux             #+#    #+#             */
/*   Updated: 2022/08/06 00:46:58 by alfux            ###   ########.fr       */
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
		if (ply->grd[i] == (t_grd)-1)
			ft_printf("%s|    ", GREEN, RED, ply->grd[i++]);
		else
			ft_printf("%s| %s%2i ", GREEN, RED, ply->grd[i++]);
	}
	ft_printf("%s|%s\n", GREEN, WHITE);
}

int	ft_scrbrd(t_ply *ply)
{
	int	i;
	int	mx;

	i = 0;
	mx = ft_maxsze(ply);
	while ((ply + i)->name)
		ft_pntlne(ply + i++, mx);
	return (0);
}
