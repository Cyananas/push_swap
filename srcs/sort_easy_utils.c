/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_easy_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:48:08 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 13:28:23 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_pos_min(t_stack *stack)
{
	int	i;
	int	nb;
	int	count;

	i = 0;
	count = 0;
	nb = ft_min_nb(stack);
	while (stack)
	{
		if (stack->nb == nb)
			return (count);
		count++;
		stack = stack->next;
	}
	return (count);
}

int		ft_pos_max(t_stack *stack)
{
	int i;
	int nb;
	int count;

	i = 0;
	count = 0;
	nb = ft_max_nb(stack);
	while (stack)
	{
		if (stack->nb == nb)
			return (count);
		count++;
		stack = stack->next;
	}
	return (count);
}

int		ft_max_nb(t_stack *stack)
{
	int max;

	max = stack->nb;
	while (stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	return (max);
}

int		ft_min_nb(t_stack *stack)
{
	int min;

	min = stack->nb;
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}
