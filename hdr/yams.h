/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yams.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfux <alexis.t.fuchs@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:05:20 by alfux             #+#    #+#             */
/*   Updated: 2022/08/05 02:31:07 by alfux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef YAMS_H
# define YAMS_H
# include "libft.h"
# include <readline/readline.h>
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define WHITE "\033[0m"

enum					e_grd
{
	ONE,
	TWO,
	THR,
	FOU,
	FIV,
	SIX,
	BRE,
	LIT,
	BIG,
	FUL,
	SQU,
	YAM,
	LUC,
	NBC
};
typedef enum e_grd		t_grd;

struct					s_ply
{
	char	*name;
	char	*move;
	int		score;
	t_grd	grd[13];
};
typedef struct s_ply	t_ply;

//Returns allocated memory array with player stats
t_ply	*ft_getprm(int ac, char **av);
//Prints starter flag with player names
int		ft_print_players(t_ply *ply);
int		ft_yams(t_ply *ply, char **cmb);
int		ft_parse(t_ply *ply, char **cmb);
#endif
