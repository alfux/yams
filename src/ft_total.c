/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_total.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 07:22:41 by alfux             #+#    #+#             */
/*   Updated: 2022/08/06 07:39:35 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "yams.h"

int	ft_total(t_grd *grd)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < 13)
	{
		if ((int)grd[i] >= 0)
			total += grd[i];
		if (i == 5 && total >= 63)
			total += 35;
		i++;
	}
	return (total);
}
