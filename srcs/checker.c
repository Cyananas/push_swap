/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:40:03 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 12:20:27 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
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
			cmd(&a, &b);
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
