/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desperatehw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:47:38 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/17 01:47:38 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_length(t_list *stack)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	findminpos(t_list *stack)
{
	long long int	min;
	int				pos;
	int				i;
	t_list			*tmp;

	min = stack->nnumb;
	pos = 0;
	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->nnumb < min)
		{
			min = tmp->nnumb;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	magicrotate(t_stuff *stuff, int i)
{
	int	len;

	len = list_length(stuff->stacka);
	if (i <= len / 2)
	{
		while (i--)
			ft_ra(stuff, RA);
	}
	else
	{
		i = len - i;
		while (i--)
			ft_rra(stuff, RRA);
	}
	pb(stuff);
}

void	findandpush2min(t_stuff *stuff)
{
	int	minpos;

	minpos = findminpos(stuff->stacka);
	magicrotate(stuff, minpos);
}

void	arrange5(t_stuff *stuff)
{
	if (!(stuff))
		return ;
	findandpush2min(stuff);
	findandpush2min(stuff);
	arrange3(stuff);
	pa(stuff);
	pa(stuff);
}
