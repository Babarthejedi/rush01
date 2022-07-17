/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   personal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoignar <amoignar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:30:40 by amoignar          #+#    #+#             */
/*   Updated: 2022/07/17 19:44:29 by amoignar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSONAL_H
# define PERSONAL_H

# include <unistd.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	init_4_horizontal(int *str, int tab[4][4][4],
			int i, int j, int k, int l);
void	init_skyscrapers(int *str, int tab[4][4][4]);
void	init_1(int *str, int tab[4][4][4], int i, int j);
void	init_4_vertical(int *str, int tab[4][4][4], int i, int j, int k, int l);
void	ft_fill_tab(int tab[4][4][4]);
void	ft_print_tab(int tab[4][4][4]);
int		*atoi_input(char *str, int tab[16]);
int		check_input(char *line_val, int nb_arg);
int		check_errors(char *line_val, int nb_arg);
int		check_line_l(int tab[4][4][4], int str[16], int pos);
int		check_line_r(int tab[4][4][4], int str[16], int pos);
int		check_col_up(int tab[4][4][4], int str[16], int pos);
int		check_col_down(int tab[4][4][4], int str[16], int pos);
int		check_line_col(int tab[4][4][4], int str[16], int pos);
#endif