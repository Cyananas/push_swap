/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_strat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 13:38:48 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 15:36:09 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	apply_strat(t_alg *strat, t_stack **a, t_stack **b)
{
	while (strat->nbr_rot--)
	{
		if (strat->rev_a && strat->rev_b)
			ft_rev_rotate_both(a, b, TRUE);
		else
			ft_rotate_both(a, b, TRUE);
	}
	while (strat->nbr_rot_a--)
	{
		if (strat->rev_a)
			ft_reverse_rotate(a, 'a', TRUE);
		else
			ft_rotate(a, 'a', TRUE);
	}
	while (strat->nbr_rot_b--)
	{
		if (strat->rev_b)
			ft_reverse_rotate(b, 'b', TRUE);
		else
			ft_rotate(b, 'b', TRUE);
	}
	ft_push(a, b, 'b', TRUE);
}
