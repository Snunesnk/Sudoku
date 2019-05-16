/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 22:52:56 by snunes            #+#    #+#             */
/*   Updated: 2019/05/16 22:56:37 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdio.h>

int check_bloc(int nb, int grille[9][9], int posx, int posy);
int check_line(int nb, int grille[9][9], int posy);
int check_column(int nb, int grille[9][9], int posx);
int ft_resolve(int grille[9][9], int nb, int pos);

#endif
