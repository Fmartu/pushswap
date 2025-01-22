/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:53:35 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/22 16:53:17 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_printlist(t_list *head) {
    t_list *current = head;
    while (current != NULL) {
        printf("%d -> ", current->nnumb);
        current = current->next;
    }
    printf("NULL\n");
}
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

void	exeall(t_stuff *stuff)
{
	phase1(stuff);
	arrange3(stuff);
	bempy(stuff);
	lawnreorder(stuff);
}

int	main(int ac, char **av)
{
	t_stuff	stuff;
	int i;
	
	i = 0;
	stuff.ssize = 0;
	stuff.lst = 0;
	if(ac == 2)
	{
		newav(av, &stuff);
		ac = stuff.ssize;
		av = stuff.lst; 
		i++;
	}
	if ((!(av[1])) || checker(ac, av, 0, 0) != 0)
	{
		if (av[1] && checker(ac, av, 0, 0) != 0)
			err(1);
		return (err(1));
	}
	inizializer(&stuff);
	if(i != 0)
		stuff.stacka = createlist(ac, av);
	else
		stuff.stacka = createlist(ac - 1, av + 1);
	if (alreadystraight(stuff.stacka) == true)
		return (0);
	if ((ac == 6 && i == 0) || (ac == 5 && i != 0))
		{
			arrange5(&stuff);
			printf("pd");
		}
	else
	{
		if ((ac == 3 && i == 0) || (ac == 2 && i != 0))
			sa(&stuff, SA);
		else
			exeall(&stuff);
	}
	ft_printlist(stuff.stacka);
	free_list(stuff.stacka);
	return (0);
}
