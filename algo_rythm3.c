/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rythm3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:32:18 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/12 18:07:12 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	todomove(t_stuff *stuff)
{
	int		*best;
	int		*temp;
	t_list	*tmplist;

	if (!stuff->stackb)
		return ;
	tmplist = stuff->stackb->next;
	best = bigret(stuff, stuff->stackb->nnumb);
	temp = 0;
	while (tmplist)
	{
		temp = bigret(stuff, tmplist->nnumb);
		best = bestwowmove(best, temp);
		tmplist = tmplist->next;
	}
	laststrach(stuff, best);
	pa(stuff);
	free(best);
}

void	lastnorm(t_stuff *stuff, int *num1, int *num2, bool bo)
{
	if (*num1 > 0)
	{
		*num2 -= *num1;
		exemoverr(stuff, *num1, bo);
		*num1 = 0;
	}
}

void	laststrach(t_stuff *stuff, int *com)
{
	if (com[1] == com[3])
	{
		if (com[0] >= com[2])
			lastnorm(stuff, &(com[2]), &(com[0]), com[3]);
		else
			lastnorm(stuff, &(com[0]), &(com[2]), com[3]);
	}
	if (com[1] == true && com[0] > 0)
		exemover(stuff, com[0], ft_rb, RB);
	else if (com[0] > 0)
		exemover(stuff, com[0], ft_rrb, RRB);
	if (com[3] == true && com[2] > 0)
		exemover(stuff, com[2], ft_ra, RA);
	else if (com[2] > 0)
		exemover(stuff, com[2], ft_rra, RRA);
}

void	exemover(t_stuff *stuff, int n, void (*f)(t_stuff *, int), int dajeroma)
{
	while (n > 0)
	{
		(*f)(stuff, dajeroma);
		n--;
	}
}

void	exemoverr(t_stuff *stuff, int n, bool check)
{
	while (n > 0)
	{
		if (check == true)
			ft_rr(stuff);
		else if (check == false)
			ft_rrr(stuff);
		n--;
	}
}
