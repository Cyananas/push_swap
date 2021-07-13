/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:12:44 by pravry            #+#    #+#             */
/*   Updated: 2021/05/27 13:54:22 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	char	**tab;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	tab = NULL;
	if (ac >= 2)
		tab = create_src(av);
	if (tab)
	{
		if (check_src(tab) && create_stack(tab, &a))
		{
			ft_free_tab(tab);
			sort_push(&a, &b);
		}
		else
		{
			ft_free_tab(tab);
			ft_putstr_fd("Error\n", 2);
		}
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
