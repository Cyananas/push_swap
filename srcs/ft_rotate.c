/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:10:35 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 13:01:40 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_ope_rotate_up(t_stack *stack)
{
	int	src;
	int tmp;

	src = stack->nb;
	while (stack->next)
	{
		tmp = stack->nb;
		stack->nb = stack->next->nb;
		stack->next->nb = tmp;
		stack = stack->next;
	}
	stack->nb = src;
}

void		ft_rotate(t_stack **stack, char c, enum e_bol display)
{
	if (c == 'a' && display == TRUE)
		ft_putstr("ra\n");
	else if (c == 'b' && display == TRUE)
		ft_putstr("rb\n");
	if (ft_size_stack(*stack) < 2)
		return ;
	ft_ope_rotate_up(*stack);
}

void		ft_rotate_both(t_stack **a, t_stack **b, enum e_bol display)
{
	if (display == TRUE)
		ft_putstr("rr\n");
	ft_rotate(a, 'a', FALSE);
	ft_rotate(b, 'b', FALSE);
}
