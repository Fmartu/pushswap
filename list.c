/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:43:27 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/22 14:52:50 by fmartusc         ###   ########.fr       */
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
