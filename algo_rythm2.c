/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_rythm2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:53:06 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/05 17:53:06 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pnode(t_list *stackx, int value, int sizex)
{
	t_list	*stmp;
	int		l;

	stmp = stackx;
	l = 0;
	while (stmp != NULL)
	{
		if (stmp->nnumb == value)
		{
			break ;
		}
		stmp = stmp->next;
		l++;
	}
	(void)sizex;
	if (l > sizex / 2)
		return (sizex - l);
	return (l);
}

bool	boopnode(t_list *stackx, int value, int sizex)
{
	t_list	*stmp;
	int		l;

	stmp = stackx;
	l = 0;
	while (stmp != NULL)
	{
		if (stmp->nnumb == value)
		{
			break ;
		}
		stmp = stmp->next;
		l++;
	}
	(void)sizex;
	if (l > sizex / 2)
		return (false);
	return (true);
}

int	stackarot(t_stuff *stuff, int n)
{
	t_list	*temp;
	int		i;

	temp = stuff->stacka;
	i = temp->nnumb;
	while (temp->next)
	{
		if ((n > temp->nnumb) && (n < temp->next->nnumb))
		{
			return (temp->next->nnumb);
		}
		temp = temp->next;
	}
	return (i);
}

int	*bigret(t_stuff *stuff, int n)
{
	int	*result;

	result = malloc(4 * sizeof(int));
	if (!result)
		return (NULL);
	result[0] = 0;
	result[1] = 0;
	result[2] = 0;
	result[3] = 0;
	result[0] = (int)pnode(stuff->stackb, n, stuff->sizeb);
	result[1] = (int)boopnode(stuff->stackb, n, stuff->sizeb);
	result[2] = (int)pnode(stuff->stacka, stackarot(stuff, n), stuff->sizea);
	result[3] = (int)boopnode(stuff->stacka, stackarot(stuff, n), stuff->sizea);
	return (result);
}

int	*bestwowmove(int *best, int *numnow)
{
	int	a;
	int	b;

	a = best[0] + best[2];
	b = numnow[0] + numnow[2];
	if ((best[1] && best[3]) || (!best[1] && !best[3]))
	{
		if (best[0] > best[2])
			a = a - best[2];
		else
			a = a - best[0];
	}
	if ((numnow[1] && numnow[3]) || (!numnow[1] && !numnow[3]))
	{
		if (numnow[0] > numnow[2])
			b = b - numnow[2];
		else
			b = b - numnow[0];
	}
	if (a <= b)
		return (bestwowmove2(best, numnow));
	else
		return (bestwowmove2(numnow, best));
}
