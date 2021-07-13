/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_opti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:35:25 by pravry            #+#    #+#             */
/*   Updated: 2021/05/24 19:20:57 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	keep_less_op(t_alg *strat, t_alg *rules)
{
	strat->nbr_rot_a = rules->nbr_rot_a;
	strat->nbr_rot_b = rules->nbr_rot_b;
	strat->nbr_rot = rules->nbr_rot;
	strat->nbr_op = rules->nbr_op;
	strat->rev_a = rules->rev_a;
	strat->rev_b = rules->rev_b;
}

t_alg	*calc_opti(t_stack **a, t_stack **b)
{
	t_alg	*rules;
	t_alg	*strat;
	t_stack *tmp;
	int		pos;

	pos = 0;
	rules = NULL;
	strat = NULL;
	rules_init(&rules, &strat);
	calc_a_rev(a, strat, pos);
	tmp = *a;
	calc_b_cmd(b, strat, tmp->nb);
	while (tmp)
	{
		calc_a_rev(a, rules, pos);
		calc_b_cmd(b, rules, tmp->nb);
		if (rules->nbr_op < strat->nbr_op)
			keep_less_op(strat, rules);
		pos++;
		tmp = tmp->next;
	}
	free(rules);
	rules = NULL;
	return (strat);
}
