/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 21:39:22 by snunes            #+#    #+#             */
/*   Updated: 2019/05/16 23:01:08 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	check_bloc(int nb, int grille[9][9], int posx, int posy)
{
	int x;
	int y;
	int	check;

	check = 0;
	x = posx - posx % 3;
	y = posy - posy % 3;
	while (check != 9)
	{
		if (grille[y][x] == nb)
			return (0);
		x++;
		check++;
		if (check % 3 == 0)
		{
			y++;
			x = posx - posx % 3;
		}
	}
	return (1);
}

int	check_line(int nb, int grille[9][9], int posy)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grille[posy][i] == nb)
			return (0);
		i++;
	}
	return (1);
}
int	check_column(int nb, int grille[9][9], int posx)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grille[i][posx] == nb)
			return (0);
		i++;
	}
	return (1);
}

void	print_grille(int grille[9][9])
{
	int y;
	int x;

	y = 0;
	while (y < 9)
	{
		x = 0;
		while (x < 9)
			printf("%d ", grille[y][x++]);
		if (y != 8)
			printf("\n");
		y++;
	}
}

int	main(void)
{
	int nb;
	int grille[9][9];

	nb = 1;
	grille[9][9] =	{{9,0,0,1,0,0,0,0,5},
	{0,0,5,0,9,0,2,0,1},
	{8,0,0,0,4,0,0,0,0},
	{0,0,0,0,8,0,0,0,0},
	{0,0,0,7,0,0,0,0,0},
	{0,0,0,0,2,6,0,0,9},
	{2,0,0,3,0,0,0,0,6},
	{0,0,0,2,0,0,9,0,0},
	{0,0,1,9,0,4,5,7,0}};

	if (!ft_resolve(grille, nb, 0))
	{
		printf("grille non resovable\n");
		return (0);
	}
	print_grille(grille);
	return (0);	
}
