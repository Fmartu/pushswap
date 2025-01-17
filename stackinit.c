/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:45:34 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/12 18:05:22 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	inizializer(t_stuff *stuff)
{
	stuff->stacka = NULL;
	stuff->stackb = NULL;
	stuff->sizea = 0;
	stuff->sizeb = 0;
	stuff->thirda = 0;
	stuff->thirdb = 0;
}
