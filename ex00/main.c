/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoignar <amoignar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:25:55 by amoignar          #+#    #+#             */
/*   Updated: 2022/07/17 19:35:03 by amoignar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "personal.h"

int check_double(int tab[4][4][4], int pos, int num)
{
	int i;

	i = -1;
	while (++i < pos / 4)
		if (tab[i][pos % 4][0] == num)
			return (1);
	i = -1;
	while (++i < pos % 4)
		if (tab[pos / 4][i][0] == num)
			return (1);
	return (0);
}

int solve(int tab[4][4][4], int str[16], int pos)
{
	int size;

	if (pos == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (check_double(tab, pos, size) == 0)
		{
			tab[pos / 4][pos % 4][0] = size;
			if (check_line_col(tab, str, pos) == 1)
			{
				if (solve(tab, str, pos + 1) == 1)
					return (1);
			}
			else
				tab[pos / 4][pos % 4][0] = 0;
		}
	}
	return (0);
}

int main (int argc, char **argv)
{
	int tab[4][4][4];
	int	str[16]; 
	if (check_errors(argv[1], argc) == 1)
		return (0);
	atoi_input(argv[1], str);
	ft_fill_tab(tab);
	init_skyscrapers(str, tab);
	solve(tab, str, 0);
	ft_print_tab(tab);
	return (0);
}
    