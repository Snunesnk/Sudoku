/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_sudoku.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 22:17:00 by snunes            #+#    #+#             */
/*   Updated: 2019/05/16 23:02:48 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int check_all(int nb, int grille[9][9], int x, int y)
{
	if (!check_bloc(nb, grille, x, y))
		return (0);
	if (!check_line(nb, grille, y))
		return (0);
	if (!check_column(nb, grille, x))
		return (0);
	return (1);
}

int find_space(int *posx, int *posy, int grille)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (grille[y][x] != 0)
	{
		if (x == 8)
		{
			if (y == 8)
				return (0);
			x = 0;
			y++;
		}
		x++;
	}
	*posx = x;
	*posy = y;
	return (1);
}

int	ft_resolve(int grille[9][9], int nb, int pos)
{
	int x;
	int y;
	
	if (nb == 10)
		return (0);
	if (pos == 81)
		return (1);
	x = pos % 9;
	y = (pos - x) / 9;
	if (grille[y][x])
		return (ft_resolve(grille, nb, pos++));
	if (check_all(nb, grille, x, y))
	{
		grille[y][x] = nb;
		nb = 1;
		return (ft_resolve(grille, nb, pos++));
	}
	return (ft_resolve(grille, nb++, pos));
}
