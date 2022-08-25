/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:15:41 by alfux             #+#    #+#             */
/*   Updated: 2022/08/25 23:47:57 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "yams.h"

static int	ft_fndcmd(char *cmd, char **cmb)
{
	int	i;

	i = 0;
	if (!ft_strncmp(cmd, "exit", 5))
		return (NBC);
	if (!ft_strncmp(cmd, "scr", 4))
		return (NBC + 2);
	while (i < NBC)
	{
		if (!ft_strncmp(cmd, *(cmb + i),
				ft_minof(ft_strlen(cmd), ft_strlen(*(cmb + i)))))
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_freesplit(char **spl)
{
	int	i;

	i = 0;
	while (*(spl + i))
		free(*(spl + i++));
	free(spl);
	return (0);
}

static int	ft_isinteger(char *n)
{
	int	i;

	if (*n == '+')
		n++;
	i = 0;
	while (*(n + i))
		if (!ft_isdigit(*(n + i++)))
			return (0);
	if (i > 10)
		return (0);
	else if (i == 10 && ft_strncmp("2147483647", n, 10) < 0)
		return (0);
	return (1);
}

static int	ft_addpnt(char **spl, int i)
{
	if (*(spl + 1) && ft_isinteger(*(spl + 1)))
		return (ft_atoi(*(spl + 1)));
	else if (*(spl + 1))
		return (-1);
	else if (i == YAM)
		return (50);
	else if (i == SQU)
		return (40);
	else if (i == FUL)
		return (30);
	else if (i == LIT || i == BIG)
		return (25);
	else
		return (-1);
}

int	ft_parse(char *cmd, t_ply *ply, char **cmb)
{
	int		i;
	char	**spl;

	spl = ft_split(cmd, ' ');
	if (!spl)
		return (-2);
	if (!*spl)
		return (ft_freesplit(spl));
	i = ft_fndcmd(*spl, cmb);
	if (i == NBC)
		return (ft_freesplit(spl) - 1);
	if (i == NBC + 2)
		return (ft_freesplit(spl) + 3);
	if (i < 0)
		return (ft_freesplit(spl) * ft_printf("%s/!\\ Syntax%s\n", RED, WHITE));
	if (ply->grd[i] == (t_grd)-1)
		ply->grd[i] = ft_addpnt(spl, i);
	else
		return (ft_freesplit(spl) * ft_printf(
				"%s%s's case is already filled%s\n", RED, ply->name, WHITE));
	if (ply->grd[i] == (t_grd)-1)
		return (ft_freesplit(spl) * ft_printf("%s/!\\ Syntax%s\n", RED, WHITE));
	return (ft_freesplit(spl) + 1);
}
