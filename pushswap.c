/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:53:35 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/23 18:30:53 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lawnreorder(t_stuff *stuff)
{
	if (stuff->stacka->nnumb < stuff->thirda)
	{
		while (stuff->stacka->nnumb != stuff->min)
		{
			ft_rra(stuff, RRA);
		}
	}
	else
	{
		while (stuff->stacka->nnumb != stuff->min)
		{
			ft_ra(stuff, RA);
		}
	}
}

void	free_matrix(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

void	exeall(t_stuff *stuff)
{
	phase1(stuff);
	arrange3(stuff);
	bempy(stuff);
	lawnreorder(stuff);
}

int	main2(int acci, char **avvi, int i, t_stuff *stuff)
{
	if (i != 0)
		stuff->stacka = createlist(acci, avvi);
	else
		stuff->stacka = createlist(acci - 1, avvi + 1);
	if (alreadystraight(stuff->stacka) == true)
		return (free_list(stuff->stacka), 0);
	if ((acci == 6 && i == 0) || (acci == 5 && i != 0))
		arrange5 (stuff);
	else
	{
		if ((acci == 3 && i == 0) || (acci == 2 && i != 0))
			sa(stuff, SA);
		else
			exeall(stuff);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stuff	stuff;
	int		i;

	i = 0;
	stuff.ssize = 0;
	stuff.lst = 0;
	if (ac == 2)
	{
		newav(av, &stuff);
		ac = stuff.ssize;
		av = stuff.lst;
		i++;
	}
	if ((!(av[1])) || checker(ac, av, 0, 0) != 0)
	{
		if (av[1] && checker(ac, av, 0, 0) != 0)
			return (err(1));
		return (0);
	}
	inizializer(&stuff);
	if (main2(ac, av, i, &stuff) == 0)
		return (free_matrix(stuff.lst), 0);
	if (stuff.lst)
		free_matrix(stuff.lst);
	return (free_list(stuff.stacka), 0);
}
