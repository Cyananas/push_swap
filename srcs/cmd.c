/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:14:14 by pravry            #+#    #+#             */
/*   Updated: 2021/05/25 12:41:35 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		exec_cmd(t_list *ope, t_stack **a, t_stack **b, int flag_exit)
{
	if (!flag_exit)
	{
		while (ope)
		{
			apply_cmd((char *)ope->content, a, b);
			ope = ope->next;
		}
	}
	if (ft_check_sorted(a, b) && !flag_exit)
		ft_putstr("OK\n");
	else if (!ft_check_sorted(a, b) && !flag_exit)
		ft_putstr("KO\n");
}

static void		add_cmd(t_list **ope, char *cmd)
{
	t_list	*tmp;
	char	*s;

	s = NULL;
	if (cmd)
		s = ft_strdup(cmd);
	tmp = ft_lstnew(s);
	if (!tmp)
		return ;
	ft_lstadd_back(ope, tmp);
}

static	int		check_cmd(char *s)
{
	if (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb") || !ft_strcmp(s, "ss")
		|| !ft_strcmp(s, "ra")
		|| !ft_strcmp(s, "rb") || !ft_strcmp(s, "rr") || !ft_strcmp(s, "rra")
		|| !ft_strcmp(s, "rrb") || !ft_strcmp(s, "rrr") || !ft_strcmp(s, "pa")
		|| !ft_strcmp(s, "pb"))
		return (1);
	return (0);
}

static int		check_break(char *cmd)
{
	if (!check_cmd(cmd))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

void			cmd(t_stack **a, t_stack **b)
{
	char	*commande;
	t_list	*ope;
	int		gnl;
	int		flag_exit;

	gnl = 1;
	flag_exit = 0;
	ope = NULL;
	while (gnl >= 0)
	{
		gnl = ft_gnl_check(0, &commande, flag_exit);
		if (!gnl)
		{
			if (!flag_exit)
				free(commande);
			break ;
		}
		flag_exit = check_break(commande);
		add_cmd(&ope, commande);
		free(commande);
	}
	exec_cmd(ope, a, b, flag_exit);
	ft_lstclear(&ope, &ft_lstfree_content);
}
