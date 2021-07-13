/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_nbr_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:18:53 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 12:19:49 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calc_b_cmd(t_stack **b, t_alg *rules, int nb)
{
	int	size;
	int	pos;

	pos = get_pos_dest(nb, b);
	rules->nbr_rot_b = pos;
	rules->rev_b = 0;
	size = ft_size_stack(*b);
	if (pos >= size / 2)
	{
		rules->nbr_rot_b = size - pos;
		rules->rev_b = 1;
	}
	calc_strat(rules);
}

void	calc_a_rev(t_stack **a, t_alg *rules, int pos)
{
	int	size;

	size = ft_size_stack(*a);
	rules->nbr_rot_a = pos;
	rules->rev_a = 0;
	if (pos >= size / 2)
	{
		rules->nbr_rot_a = size - pos;
		rules->rev_a = 1;
	}
}

void	calc_strat(t_alg *rules)
{
	rules->nbr_rot = 0;
	if (rules->rev_a == rules->rev_b)
	{
		if (rules->nbr_rot_a < rules->nbr_rot_b)
		{
			rules->nbr_rot = rules->nbr_rot_a;
			rules->nbr_rot_b -= rules->nbr_rot_a;
			rules->nbr_rot_a = 0;
		}
		else if (rules->nbr_rot_a > rules->nbr_rot_b)
		{
			rules->nbr_rot = rules->nbr_rot_b;
			rules->nbr_rot_a -= rules->nbr_rot_b;
			rules->nbr_rot_b = 0;
		}
		else
		{
			rules->nbr_rot = rules->nbr_rot_a;
			rules->nbr_rot_a = 0;
			rules->nbr_rot_b = 0;
		}
	}
	rules->nbr_op = rules->nbr_rot_a + rules->nbr_rot_b + rules->nbr_rot;
}
