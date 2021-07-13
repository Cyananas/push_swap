/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:38:03 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 13:00:55 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_ope_rotate_down(t_stack *stack)
{
	int		i;
	t_stack	*tmp;
	int		prev;
	int		next;

	i = 0;
	prev = stack->nb;
	tmp = stack;
	stack = stack->next;
	while (stack->next)
	{
		next = stack->nb;
		stack->nb = prev;
		prev = next;
		stack = stack->next;
	}
	next = stack->nb;
	stack->nb = prev;
	stack = tmp;
	stack->nb = next;
}

void			ft_reverse_rotate(t_stack **stack, char c, enum e_bol display)
{
	if (c == 'a' && display == TRUE)
		ft_putstr("rra\n");
	else if (c == 'b' && display == TRUE)
		ft_putstr("rrb\n");
	if (ft_size_stack(*stack) < 2)
		return ;
	ft_ope_rotate_down(*stack);
}

void			ft_rev_rotate_both(t_stack **a, t_stack **b, enum e_bol display)
{
	if (display == TRUE)
		ft_putstr("rrr\n");
	ft_reverse_rotate(a, 'a', FALSE);
	ft_reverse_rotate(b, 'b', FALSE);
}
