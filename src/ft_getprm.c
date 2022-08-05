/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:23:56 by alfux             #+#    #+#             */
/*   Updated: 2022/08/06 00:33:40 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "yams.h"

t_ply	*ft_getprm(int ac, char **av)
{
	t_ply	*players;
	int		i;

	players = ft_calloc(ac, sizeof (t_ply));
	if (!players)
		return ((t_ply *)0);
	i = -1;
	while (++i < ac - 1)
	{
		(players + i)->name = *(av + i + 1);
		ft_memset((players + i)->grd, -1, 13 * sizeof (t_grd));
	}
	return (players);
}
