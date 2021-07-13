/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_to_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:18:44 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 13:14:40 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	last_rotates(t_stack **a)
{
	int	op;
	int	pos;

	pos = ft_pos_min(*a);
	op = pos;
	if (pos >= ft_size_stack(*a) / 2)
		op = ft_size_stack(*a) - pos;
	while (op--)
	{
		if (pos < ft_size_stack(*a) / 2)
			ft_rotate(a, 'a', TRUE);
		else
			ft_reverse_rotate(a, 'a', TRUE);
	}
}

void	pop(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;
	int	op;

	while (ft_size_stack(*b) > 0)
	{
		pos = get_pos((*b)->nb, a);
		op = pos;
		size = ft_size_stack(*a);
		if (pos >= size / 2)
			op = size - pos;
		while (op--)
		{
			if (pos < ft_size_stack(*a) / 2)
				ft_rotate(a, 'a', TRUE);
			else
				ft_reverse_rotate(a, 'a', TRUE);
		}
		ft_push(b, a, 'a', TRUE);
	}
	last_rotates(a);
}

void	get_to_top(t_stack **a, t_stack **b)
{
	int	pos;
	int	size;

	pos = 0;
	size = ft_size_stack(*a);
	while (size > 2)
	{
		pos = ft_pos_min(*a);
		size = ft_size_stack(*a);
		if (pos == 0)
			ft_push(a, b, 'b', TRUE);
		else if (pos < size / 2)
			ft_rotate(a, 'a', TRUE);
		else
			ft_reverse_rotate(a, 'a', TRUE);
	}
	pop(a, b);
}
