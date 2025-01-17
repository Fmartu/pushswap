/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:43:27 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/12 18:05:56 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

t_list	*createnode(int nnumb)
{
	t_list	*stack;

	stack = (t_list *)malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	stack->nnumb = nnumb;
	stack->next = NULL;
	return (stack);
}

t_list	*createlist(int ac, char **av)
{
	int		i;
	t_list	*head;
	t_list	*current;

	i = 1;
	if (ac <= 0 || !av)
		return (NULL);
	head = createnode(ft_atol(av[0]));
	current = head;
	while (i < ac)
	{
		current->next = createnode(ft_atol(av[i]));
		current = current->next;
		i++;
	}
	return (head);
}

void	print_list(t_list *top)
{
	t_list	*current;

	current = top;
	while (current)
		current = current->next;
}

void	free_list(t_list *top)
{
	t_list	*current;
	t_list	*temp;

	current = top;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

void	arrange5(t_stuff *stuff)
{
	if (stuff->stackb->nnumb > stuff->stackb->next->nnumb)
		sb(stuff, SB);
	while (stuff->stackb && stuff->stackb->nnumb)
	{
		if (stuff->stackb && (stuff->stackb->nnumb < stuff->stacka->nnumb))
			pa(stuff);
		else if (stuff->stackb->nnumb > stuff->stacka->nnumb)
			ft_ra(stuff, RA);
	}
}
