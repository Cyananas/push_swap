/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:12:45 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 15:33:57 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack **stack, char c, enum e_bol display)
{
	int	nb1;
	int	nb2;

	if (c == 'a' && display == TRUE)
		ft_putstr("sa\n");
	else if (c == 'b' && display == TRUE)
		ft_putstr("sb\n");
	if (ft_size_stack(*stack) < 2)
		return ;
	nb1 = (*stack)->nb;
	nb2 = (*stack)->next->nb;
	(*stack)->nb = nb2;
	(*stack)->next->nb = nb1;
}

void	ft_swap_both(t_stack **a, t_stack **b, enum e_bol display)
{
	if (display == TRUE)
		ft_putstr("ss\n");
	ft_swap(a, 'a', FALSE);
	ft_swap(b, 'b', FALSE);
}

void	ft_push(t_stack **src, t_stack **dest, char c, enum e_bol display)
{
	t_stack *stock;

	if (c == 'a' && display == TRUE)
		ft_putstr("pa\n");
	else if (c == 'b' && display == TRUE)
		ft_putstr("pb\n");
	if (ft_size_stack(*src) == 0)
		return ;
	stock = new_elem_stack((*src)->nb);
	add_elem(dest, stock);
	free_elem_stack(src);
}
