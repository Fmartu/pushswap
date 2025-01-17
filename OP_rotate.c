/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OP_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:14:37 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/12 18:06:16 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stuff *stuff, int op)
{
	t_list	*tmp;
	t_list	*dajeroma;

	tmp = stuff->stacka;
	dajeroma = stuff->stacka->next;
	while (stuff->stacka->next != NULL)
	{
		stuff->stacka = stuff->stacka->next;
	}
	stuff->stacka->next = tmp;
	stuff->stacka = stuff->stacka->next;
	stuff->stacka->next = NULL;
	stuff->stacka = dajeroma;
	ope(op);
}

void	ft_rb(t_stuff *stuff, int op)
{
	t_list	*tmp;
	t_list	*dajeroma;

	if (stuff->sizeb < 2)
		return ;
	tmp = stuff->stackb;
	dajeroma = stuff->stackb->next;
	while (stuff->stackb->next != NULL)
	{
		stuff->stackb = stuff->stackb->next;
	}
	stuff->stackb->next = tmp;
	stuff->stackb = stuff->stackb->next;
	stuff->stackb->next = NULL;
	stuff->stackb = dajeroma;
	ope(op);
}

void	ft_rr(t_stuff *stuff)
{
	ft_ra(stuff, -1);
	ft_rb(stuff, -1);
	ope(RR);
}
