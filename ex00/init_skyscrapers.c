/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skyscrapers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoignar <amoignar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:57:35 by maujogue          #+#    #+#             */
/*   Updated: 2022/07/17 19:55:49 by amoignar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_tab(int tab[4][4][4])
{
	int	i;
	int	j;
	int	tmp;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		while (j < 4)
		{	
			while (k < 4)
			{
				if (tab[j][i][k] != 0)
				{
					tmp = tab[j][i][k] + '0';
					write(1, &tmp, 1);
				}
				k++;
			}
			j++;
			k = 0;
			write(1, " ", 1);
		}
		i++;
		j = 0;
		write(1, "\n", 1);
	}
}

void	ft_fill_tab(int tab[4][4][4])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			while (k < 4)
			{
				tab[i][j][k] = 0;
				k++;
			}
			j++;
			k = 0;
		}
		i++;
		j = 0;
	}
}

void	init_1234(int tab[4][4][4])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (tab[i][j][0] == 0)
			{
				while (k < 4)
				{
					tab[i][j][k] = k + 1;
					k++;
				}			
			}
			j++;
			k = 0;
		}
		i++;
		j = 0;
	}
}

void	init_4_vertical(int *str, int tab[4][4][4], int i, int j, int k, int l)
{
	while (str[i] != '\0')
	{
		if (str[i] == 4 && i < 4)
		{
			while (k < 4)
			{
				tab[i][k][0] = k + 1;
				k++;
			}
		}
		else if (str[i] == 4 && i < 8)
		{
			k = 3;
			l = 1;
			while (k >= 0)
			{
				tab[j][k][0] = l;
				k--;
				l++;
			}
		}
		i++;
		if (j < 3)
			j = 0;
	}
}

void	init_4_horizontal(int *str, int tab[4][4][4],
		int i, int j, int k, int l)
{
	while (str[i] != '\0')
	{
		if (str[i] == 4 && i > 3 && i < 12)
		{
			while (k < 4)
			{
				tab[k][i - 8][0] = k + 1;
				k++;
			}
		}
		else if (str[i] == 4 && i > 11 && i < 16)
		{
			k = 3;
			l = 1;
			while (k >= 0)
			{
				tab[k][i - 12][0] = l;
				k--;
				l++;
			}
		}
		i++;
		if (j < 3)
			j = 0;
	}
}

void	init_1(int *str, int tab[4][4][4],int i, int j)
{
	while (str[i] != '\0')
	{
		if (str[i] == 1 && i < 4)
			tab[j][0][0] = 4;
		else if (str[i] == 1 && i < 8)
			tab[j][3][0] = 4;
		else if (str[i] == 1 && i < 12)
			tab[0][j][0] = 4;
		else if (str[i] == 1 && i < 16)
			tab[3][j][0] = 4;
			i++;
			j++;
		if (j == 4)
		j = 0;
	}
}

void	init_skyscrapers(int *str, int tab[4][4][4])
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	init_1(str, tab, i, j);
	init_4_vertical(str, tab, i, j, k, l);
	init_4_horizontal(str, tab, i, j, k, l);
}
