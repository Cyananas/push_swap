/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:58:12 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 15:34:32 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*new_elem_stack(int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void		add_elem(t_stack **stack, t_stack *der)
{
	if (stack)
		der->next = *stack;
	*stack = der;
}

int			ft_size_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void		free_elem_stack(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

void		free_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}
