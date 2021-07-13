/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:06:47 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 13:17:17 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_double(t_stack *stack)
{
	int		nb;
	int		i;
	int		j;
	int		size;
	t_stack *tmp;

	i = -1;
	j = 1;
	size = ft_size_stack(stack);
	tmp = stack;
	while (++i < size)
	{
		nb = tmp->nb;
		while (tmp->next)
		{
			if (nb == tmp->next->nb)
				return (0);
			tmp = tmp->next;
		}
		tmp = stack;
		while (j-- > 0)
			tmp = tmp->next;
		j = size - ft_size_stack(tmp) + 1;
	}
	return (1);
}

char		**create_src(char **av)
{
	char	**src;
	char	**tmp;
	int		i;

	i = 1;
	src = NULL;
	while (av[i])
	{
		tmp = ft_split(av[i], ' ');
		if (!tmp)
			return (NULL);
		src = ft_tab_join(src, tmp);
		if (tmp)
			ft_free_tab(tmp);
		if (!src)
			return (NULL);
		i++;
	}
	return (src);
}

int			check_src(char **tab)
{
	int	j;
	int	i;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (ft_isspace(tab[i][j]))
			j++;
		if (tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		while (ft_isdigit(tab[i][j]))
			j++;
		if (tab[i][j])
			return (0);
		i++;
	}
	return (1);
}

int			fill_stack(t_stack **stack, char **tab)
{
	int			i;
	long long	nb;
	t_stack		*der;

	i = ft_tab_len(tab) - 1;
	while (i >= 0)
	{
		nb = ft_atoi_long(tab[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (0);
		der = new_elem_stack((int)nb);
		add_elem(stack, der);
		i--;
	}
	return (1);
}

int			create_stack(char **tab, t_stack **a)
{
	if (!fill_stack(a, tab))
		return (0);
	if (!check_double(*a))
		return (0);
	return (1);
}
