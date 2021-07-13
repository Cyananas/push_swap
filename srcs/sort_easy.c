/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_easy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:48:30 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 13:26:14 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack)
{
	int		max;

	max = ft_max_nb(*stack);
	if ((*stack)->nb == max)
		ft_rotate(stack, 'a', TRUE);
	else if ((*stack)->next->nb == max)
		ft_reverse_rotate(stack, 'a', TRUE);
	if ((*stack)->nb > (*stack)->next->nb)
		ft_swap(stack, 'a', TRUE);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	pos_min;
	int	size;
	int	i;

	size = ft_size_stack(*a);
	i = 0;
	while (i < size - 3)
	{
		size = ft_size_stack(*a);
		pos_min = ft_pos_min(*a);
		if (pos_min <= size / 2)
			while (pos_min--)
				ft_rotate(a, 'a', TRUE);
		else
			while (pos_min++ < size)
				ft_reverse_rotate(a, 'a', TRUE);
		if (ft_check_sorted(a, b) == 1)
			return ;
		ft_push(a, b, 'b', TRUE);
		i++;
	}
	sort_three(a);
	while (i--)
		ft_push(b, a, 'a', TRUE);
}
