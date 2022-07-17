/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoignar <amoignar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:02:02 by amoignar          #+#    #+#             */
/*   Updated: 2022/07/17 19:46:47 by amoignar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "personal.h"

int	check_numbers(char *line_value)
{
	int	one;
	int	four;
	int	i;

	one = 0;
	four = 0;
	i = 0;
	while (line_value[i] != '\0')
	{
		if (line_value[i] == '1')
			one++;
		if (line_value[i] == '4')
			four++;
		if (four > 4 || one > 4)
		{
			ft_putstr("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_input(char *line_val, int nb_arg)
{
	int	i;

	i = 0;
	if (nb_arg != 2 || line_val[30] == ' ' || line_val[0] == '\0')
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (line_val[0] < '1' || line_val[0] > '4')
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int	check_errors(char *line_val, int nb_arg)
{
	int	i;

	i = 0;
	if (ft_strlen(line_val) != 31)
	{
		ft_putstr("Error");
		return (1);
	}	
	if (check_input(line_val, nb_arg) == 1)
		return (1);
	if (check_numbers(line_val) == 1)
		return (1);
	while (line_val[i] != '\0')
	{
		if ((line_val[i] != ' ' && line_val[i] != '1' && line_val[i] != '2'
				&& line_val [i] != '3' && line_val[i] != '4'))
		{
			ft_putstr("Error\n");
			return (1);
		}
		if (i % 2 != 0 && line_val[i] != ' ')
		{
			ft_putstr("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
