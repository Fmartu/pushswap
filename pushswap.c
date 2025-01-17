/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:53:35 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/17 16:19:34 by fmartusc         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stuff	stuff;

	if (checker(ac, av, 0, 0) != 0)
	{
		err(1);
		return (1);
	}
	inizializer(&stuff);
	stuff.stacka = createlist(ac - 1, av + 1);
	if (alreadystraight(stuff.stacka) == true)
		return (0);
	if (!(ac == 6))
	{
		phase1(&stuff);
		arrange3(&stuff);
		bempy(&stuff);
		lawnreorder(&stuff);
	}
	else if (ac == 6)
		arrange5(&stuff);
	free_list(stuff.stacka);
	return (0);
}
