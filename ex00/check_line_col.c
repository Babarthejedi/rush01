/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_col.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoignar <amoignar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 10:00:38 by maujogue          #+#    #+#             */
/*   Updated: 2022/07/17 19:16:35 by amoignar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "personal.h"

int	check_line_l(int tab[4][4][4], int str[16], int pos)
{
	int	i;
	int	max;
	int	counter;

	i = 0;
	max = 0;
	counter = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (tab[pos / 4][i][0] > max)
			{
				max = tab[pos / 4][i][0];
				counter++;
			}
			i++;
		}
		if (str[8 + pos / 4] == counter)
			return (1);
	}
	return (0);
}

int	check_line_r(int tab[4][4][4], int str[16], int pos)
{
	int	i;
	int	max;
	int	counter;

	i = 3;
	max = 0;
	counter = 0;
	if (pos % 4 == 3)
	{
		while (i >= 0)
		{
			if (tab[pos / 4][i][0] > max)
			{
				max = tab[pos / 4][i][0];
				counter++;
			}
			i--;
		}
		if (str[8 + pos / 4] == counter)
			return (1);
	}
	return (0);
}

int	check_col_up(int tab[4][4][4], int str[16], int pos)
{
	int	i;
	int	max;
	int	counter;

	i = 0;
	max = 0;
	counter = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (tab[i][pos % 4][0] > max)
			{
				max = tab[i][pos % 4][0];
				counter++;
			}
			i++;
		}
		if (str[pos % 4] == counter)
			return (1);
	}
	return (0);
}

int	check_col_down(int tab[4][4][4], int str[16], int pos)
{
	int	i;
	int	max;
	int	counter;

	i = 3;
	max = 0;
	counter = 0;
	if (pos / 4 == 3)
	{
		while (i >= 0)
		{
			if (tab[i][pos % 4][0] > max)
			{
				max = tab[i][pos % 4][0];
				counter++;
			}
			i--;
		}
		if (str[4 + pos % 4] == counter)
			return (1);
	}
	return (0);
}

int	check_line_col(int tab[4][4][4], int str[16], int pos)
{
	if (check_line_l(tab, str, pos) == 1
		&& check_line_r(tab, str, pos) == 1
		&& check_col_up(tab, str, pos) == 1
		&& check_col_down(tab, str, pos) == 1)
		return (1);
	return (0);
}
