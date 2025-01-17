/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rythm1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:17:00 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/02 23:17:00 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	eiffel(t_list *stackx, t_stuff *stuff)
{
	t_list	*tmp;
	int		ret;
	int		sum;

	tmp = stackx;
	sum = 0;
	stuff->max = tmp->nnumb;
	stuff->min = tmp->nnumb;
	while (tmp)
	{
		sum += tmp->nnumb;
		if (tmp->nnumb < stuff->min)
			stuff->min = tmp->nnumb;
		if (tmp->nnumb > stuff->max)
			stuff->max = tmp->nnumb;
		tmp = tmp->next;
	}
	ret = sum / ft_lstsize (stackx);
	return (ret);
}

void	arrange3(t_stuff *stuff)
{
	t_list			*tmp;
	long long int	b;
	long long int	c;

	tmp = stuff->stacka;
	b = tmp->next->nnumb;
	c = tmp->next->next->nnumb;
	if (((tmp->nnumb) < b) && (b > c) && (c > (tmp->nnumb)))
	{
		sa(stuff, SA);
		ft_ra(stuff, RA);
	}
	else if (((tmp->nnumb) > b) && (b < c) && (c > (tmp->nnumb)))
		sa(stuff, SA);
	else if (((tmp->nnumb) < b) && (b > c) && (c < (tmp->nnumb)))
		ft_rra(stuff, RRA);
	else if (((tmp->nnumb) > b) && (b < c) && (c < (tmp->nnumb)))
		ft_ra(stuff, RA);
	else if (((tmp->nnumb) > b) && (b > c) && (c < (tmp->nnumb)))
	{
		sa(stuff, SA);
		ft_rra(stuff, RRA);
	}
	return ;
}

void	phase1(t_stuff *stuff)
{
	t_list	*tmp;

	tmp = stuff->stacka;
	stuff->sizea = ft_lstsize(stuff->stacka);
	stuff->thirda = eiffel(stuff->stacka, stuff);
	while (tmp && (stuff->sizea > 3))
	{
		if (tmp->nnumb == stuff->max || tmp->nnumb == stuff->min)
			ft_rra(stuff, RRA);
		else
			pb(stuff);
		if (stuff->sizeb > 2 && stuff->stackb->nnumb >= stuff->thirda)
			ft_rb(stuff, RB);
		tmp = stuff->stacka;
	}
}

bool	alreadystraight(t_list *tmp)
{
	if (tmp == NULL || tmp->next == NULL)
		return (true);
	if (tmp->nnumb > tmp->next->nnumb)
		return (false);
	return (alreadystraight(tmp->next));
}
