/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yams.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:31:59 by alfux             #+#    #+#             */
/*   Updated: 2022/08/06 07:14:50 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "yams.h"

static char	*ft_plytrn(char *name)
{
	char	*prompt;
	int		size;

	size = ft_strlen(name);
	prompt = ft_calloc(size + 21, sizeof (char));
	if (!prompt)
		return ((char *)0);
	ft_strlcpy(prompt, "\033[33m", size + 21);
	ft_strlcpy(prompt + 5, name, size + 16);
	ft_strlcpy(prompt + 5 + size, "'s turn -> \033[0m", 16);
	return (prompt);
}

static int	ft_turn(t_ply *ply, char **cmb)
{
	char	*line;
	char	*prompt;
	int		ret;

	prompt = ft_plytrn(ply->name);
	if (!prompt)
		return (0);
	line = readline(prompt);
	free(prompt);
	if (!line)
		return (0);
	ret = ft_parse(line, ply, cmb);
	free(line);
	return (ret);
}

int	ft_yams(t_ply *ply, char **cmb)
{
	int		turn;
	int		ret;
	int		i;

	turn = 0;
	while (turn++ < NBC)
	{
		i = 0;
		while ((ply + i)->name)
		{
			ret = ft_turn(ply + i, cmb);
			if (ret == -1)
				return (0);
			else if (ret == -2)
				return (1);
			else if (ret == 2)
				ft_scrbrd(ply, cmb, -1);
			else if (ret == 3)
				ft_scrbrd(ply, cmb, i);
			else if (ret)
				i++;
		}
	}
	return (0);
}
