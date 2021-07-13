/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:50:50 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 13:15:13 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rules_init(t_alg **rules, t_alg **strat)
{
	*strat = (t_alg *)malloc(sizeof(t_alg));
	if (!strat)
		return ;
	*rules = (t_alg *)malloc(sizeof(t_alg));
	if (!rules)
		return ;
	(*strat)->nbr_rot_a = 0;
	(*strat)->nbr_rot_b = 0;
	(*strat)->nbr_rot = 0;
	(*strat)->rev_a = 0;
	(*strat)->rev_b = 0;
	(*strat)->nbr_op = 0;
	(*rules)->nbr_rot_a = 0;
	(*rules)->nbr_rot_b = 0;
	(*rules)->nbr_rot = 0;
	(*rules)->rev_a = 0;
	(*rules)->rev_b = 0;
	(*rules)->nbr_op = 0;
}
