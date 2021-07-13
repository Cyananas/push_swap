/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:41:47 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 15:35:39 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	apply_cmd(char *cmd, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(cmd, "ra"))
		ft_rotate(a, 'a', FALSE);
	else if (!ft_strcmp(cmd, "rb"))
		ft_rotate(b, 'b', FALSE);
	else if (!ft_strcmp(cmd, "rr"))
		ft_rotate_both(a, b, FALSE);
	else if (!ft_strcmp(cmd, "rra"))
		ft_reverse_rotate(a, 'a', FALSE);
	else if (!ft_strcmp(cmd, "rrb"))
		ft_reverse_rotate(b, 'b', FALSE);
	else if (!ft_strcmp(cmd, "rrr"))
		ft_rev_rotate_both(a, b, FALSE);
	else if (!ft_strcmp(cmd, "sa"))
		ft_swap(a, 'a', FALSE);
	else if (!ft_strcmp(cmd, "sb"))
		ft_swap(b, 'b', FALSE);
	else if (!ft_strcmp(cmd, "ss"))
		ft_swap_both(a, b, FALSE);
	else if (!ft_strcmp(cmd, "pa"))
		ft_push(b, a, 'a', FALSE);
	else if (!ft_strcmp(cmd, "pb"))
		ft_push(a, b, 'b', FALSE);
}
