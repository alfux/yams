/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 00:16:51 by alfux             #+#    #+#             */
/*   Updated: 2022/08/04 00:56:34 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "yams.h"

int	ft_chkarg(char **av)
{
	char	*num;
	int		i;

	num = *(av + 1);
	if (*num == '+')
		num++;
	i = -1;
	while (*(num + ++i))
		if (!ft_isdigit(*(num + i)))
			return (0);
	if (i > 10)
		return (0);
	if (i == 10 && ft_strncmp("2147483647", num, 10) < 0)
		return (0);
	return (1);
}
