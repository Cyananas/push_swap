/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:06:07 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 12:45:13 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_check_a(t_stack *a)
{
	int	nb;
	int	next;

	while (a)
	{
		if (ft_size_stack(a) == 1)
			return (1);
		if (a && a->next)
		{
			nb = a->nb;
			next = a->next->nb;
		}
		if (nb < next)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int			ft_check_sorted(t_stack **a, t_stack **b)
{
	if (ft_check_a(*a) && ft_size_stack(*b) == 0)
		return (1);
	else
		return (0);
}
