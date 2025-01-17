/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OP_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:28:29 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/12 18:06:03 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stuff *stuff, int op)
{
	t_list	*tmp;
	t_list	*head;

	tmp = stuff->stacka;
	head = stuff->stacka;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	head = tmp->next;
	tmp->next = NULL;
	head->next = stuff->stacka;
	stuff->stacka = head;
	ope(op);
}

void	ft_rrb(t_stuff *stuff, int op)
{
	t_list	*tmp;
	t_list	*head;

	tmp = stuff->stackb;
	head = stuff->stackb;
	while (tmp->next->next)
		tmp = tmp->next;
	head = tmp->next;
	tmp->next = NULL;
	head->next = stuff->stackb;
	stuff->stackb = head;
	ope(op);
}

void	ft_rrr(t_stuff *stuff)
{
	ft_rra(stuff, -1);
	ft_rrb(stuff, -1);
	ope(RRR);
}
