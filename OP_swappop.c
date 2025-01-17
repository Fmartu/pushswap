/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OP_swappop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:47:03 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/12 18:06:34 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stuff *stuff, int op)
{
	t_list	*temp;
	t_list	*temp2;

	temp = stuff->stacka;
	temp2 = temp->next;
	stuff->stacka = temp2;
	temp->next = temp2->next;
	temp2->next = temp;
	ope(op);
}

void	sb(t_stuff *stuff, int op)
{
	t_list	*temp;
	t_list	*temp2;

	temp = stuff->stackb;
	temp2 = temp->next;
	stuff->stackb = temp2;
	temp->next = temp2->next;
	temp2->next = temp;
	ope(op);
}

void	ss(t_stuff *stuff)
{
	sa(stuff, SA);
	sb(stuff, SB);
	ope(3);
}

void	pa(t_stuff *stuff)
{
	t_list	*tmp;

	if (stuff->stackb == NULL)
		return ;
	tmp = stuff->stackb;
	stuff->stackb = stuff->stackb->next;
	if (stuff->stacka)
		tmp->next = stuff->stacka;
	else
		tmp->next = NULL;
	stuff->stacka = tmp;
	stuff->sizea++;
	stuff->sizeb--;
	ope(4);
}

void	pb(t_stuff *stuff)
{
	t_list	*tmp;

	if (stuff->stacka == NULL)
		return ;
	tmp = stuff->stacka;
	stuff->stacka = stuff->stacka->next;
	if (stuff->stackb)
		tmp->next = stuff->stackb;
	else
		tmp->next = NULL;
	stuff->stackb = tmp;
	stuff->sizea--;
	stuff->sizeb++;
	ope(5);
}
