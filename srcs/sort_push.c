/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:57:36 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 15:33:12 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		sort(t_stack **a, t_stack **b)
{
	int		size;
	int		chunk;
	t_alg	*strat;

	size = ft_size_stack(*a);
	chunk = 2;
	if (size > 500)
		chunk = 100;
	else if (size > 200)
		chunk = 50;
	ft_push(a, b, 'b', TRUE);
	ft_push(a, b, 'b', TRUE);
	while (size > chunk)
	{
		size = ft_size_stack(*a);
		strat = calc_opti(a, b);
		apply_strat(strat, a, b);
		free(strat);
		strat = NULL;
	}
	get_to_top(a, b);
}

void			sort_push(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_size_stack(*a);
	if (ft_check_sorted(a, b))
		return ;
	if (size == 2)
		ft_swap(a, 'a', TRUE);
	else if (size == 3)
		sort_three(a);
	else if (size == 5 || size == 4)
		sort_five(a, b);
	else
		sort(a, b);
}
