/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yams.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:31:59 by alfux             #+#    #+#             */
/*   Updated: 2022/08/05 02:36:52 by alfux            ###   ########.fr       */
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

int	ft_yams(t_ply *ply, char **cmb)
{
	char	*line;
	char	*prompt;
	int		turn;
	int		i;

	turn = 0;
	i = 0;
	while (turn < NBC)
	{
		while ((ply + i)->name)
		{
			prompt = ft_plytrn((ply + i)->name);
			if (!prompt)
				return (1);
			line = readline(prompt);
			free(prompt);
			ft_printf("%s\n", line);
			if (ft_parse(ply, cmb))
				i++;
			free(line);
		}
		turn++;
		i = 0;
	}
	return (0);
}
