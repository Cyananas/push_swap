/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:28:40 by pravry            #+#    #+#             */
/*   Updated: 2021/05/31 10:32:06 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	nb;
	int		s;

	nb = 0;
	s = 1;
	i = 0;
	while ((*(str + i) != '\0') &&
		(((*(str + i) < 14) && (*(str + i) > 8)) || (*(str + i) == 32)))
		i++;
	if (*(str + i) == 45)
	{
		s = s * -1;
		i++;
	}
	else if (*(str + i) == 43)
		i++;
	while ((*(str + i) != '\0') && (*(str + i) > 47) && (*(str + i) < 58))
	{
		nb = nb * 10 + s * (*(str + i) - 48);
		i++;
	}
	return ((int)nb);
}

int	check_double(int *tab, int nb, int index)
{
	int	i;

	i = 0;
	while (*tab)
	{
		if (*tab == nb && i != index)
			return (1);
		tab++;
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	nb;
	int	tab[ft_atoi(av[1])];

	nb = 0;
	if (ac != 2)
	{
		printf("Error");
		return (0);
	}
	i = ft_atoi(av[1]);
	while (i >= 0)
	{
		nb = rand() % 7000 - rand() % 7000;
		tab[ft_atoi(av[1] - i)] = nb;
		if (check_double(tab, nb, ft_atoi(av[1] - i)) == 1)
			i++;
		else
			printf(" %d", nb);
		i--;
	}
	printf("\n");
}
