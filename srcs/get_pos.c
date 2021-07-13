/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:50:35 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 13:13:22 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_pos(int nb, t_stack **stack)
{
	t_stack *tmp;
	int		pos;
	int		prev_nb;

	pos = 0;
	tmp = *stack;
	if (nb > ft_max_nb(*stack))
		return (ft_pos_max(*stack) + 1);
	else if (nb < ft_min_nb(*stack))
		return (ft_pos_min(*stack));
	prev_nb = (*stack)->nb;
	while (tmp)
	{
		if (prev_nb < nb && nb < tmp->nb)
			return (pos);
		prev_nb = tmp->nb;
		tmp = tmp->next;
		pos++;
	}
	return (0);
}

int		get_pos_dest(int nb, t_stack **stack)
{
	t_stack *tmp;
	int		pos;
	int		prev_nb;

	pos = 0;
	tmp = *stack;
	if (nb > ft_max_nb(*stack))
		return (ft_pos_max(*stack));
	else if (nb < ft_min_nb(*stack))
		return (ft_pos_min(*stack) + 1);
	prev_nb = (*stack)->nb;
	while (tmp)
	{
		if (prev_nb > nb && nb > tmp->nb)
			return (pos);
		prev_nb = tmp->nb;
		tmp = tmp->next;
		pos++;
	}
	return (0);
}
