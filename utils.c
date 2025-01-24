/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmartusc <fmartusc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:35:15 by fmartusc          #+#    #+#             */
/*   Updated: 2025/01/23 18:28:27 by fmartusc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atol(const char *str)
{
	int				i;
	long long int	res;
	int				sign;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	res = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	err(int ret)
{
	if (ret == 1)
		write(1, "Error\n", 6);
	return (0);
}

int	ope(int ret)
{
	if (ret == 1)
		write(1, "sa\n", 3);
	if (ret == 2)
		write(1, "sb\n", 3);
	if (ret == 3)
		write(1, "ss\n", 3);
	if (ret == 4)
		write(1, "pa\n", 3);
	if (ret == 5)
		write(1, "pb\n", 3);
	if (ret == 6)
		write(1, "ra\n", 3);
	if (ret == 7)
		write(1, "rb\n", 3);
	if (ret == 8)
		write(1, "rr\n", 3);
	if (ret == 9)
		write(1, "rra\n", 4);
	if (ret == 10)
		write(1, "rrb\n", 4);
	if (ret == 11)
		write(1, "rrr\n", 4);
	return (0);
}

int	*bestwowmove2(int *best, int *numnow)
{
	free(numnow);
	return (best);
}
