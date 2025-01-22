/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:10:56 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/21 18:17:38 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	multicheck(int ac, char **av)
{
	int				i;
	int				j;
	long long int	num1;
	long long int	num2;

	i = 1;
	while (i < ac - 1)
	{
		num1 = atoi(av[i]);
		j = i + 1;
		while (j < ac)
		{
			num2 = atoi(av[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	samesame(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checker(int ac, char **av, int i, int j)
{
	int	a;

	a = 0;
	if ((ac < 3 || (samesame(ac, av) == 1)) || (multicheck(ac, av) == 1))
		return (1);
	while (av[i] && av[i][j])
	{
		i++;
		if (av[i] && ((ft_atol(av[i]) > 2147483647)
				|| (ft_atol(av[i]) < -2147483648)))
			return (1);
		while (av[i] && av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				a++;
			if (((!((av[i][j] <= '9' && av[i][j] >= '0') || ((av[i][j] == '-'))
				|| (av[i][j] == '+')) || a > 1) || ((av[i][j] == '-'
				&& av[i][j + 1] == '0' && av[i][j + 2] == '\0'))))
				return (1);
			j++;
		}
		j = 0;
		a = 0;
	}
	return (0);
}

void	bempy(t_stuff *stuff)
{
	while (ft_lstsize(stuff->stackb) >= 1)
		todomove(stuff);
}
