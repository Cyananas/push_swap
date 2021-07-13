/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pravry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:52:33 by pravry            #+#    #+#             */
/*   Updated: 2021/05/27 14:27:25 by pravry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct		s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_alg
{
	int	nbr_rot;
	int	nbr_rot_b;
	int	nbr_rot_a;
	int	rev_b;
	int	rev_a;
	int	nbr_op;
}					t_alg;

typedef enum		e_bol
{
	TRUE,
	FALSE
}					t_bol;

void				cmd(t_stack **a, t_stack **b);
int					ft_check_sorted(t_stack **a, t_stack **b);
void				ft_free_tab(char **tab);
int					ft_gnl(int fd, char **line);
int					ft_gnl_check(int fd, char **line, int flag);
void				ft_reverse_rotate(t_stack **stack,
					char c, enum e_bol display);
void				ft_rev_rotate_both(t_stack **a,
					t_stack **b, enum e_bol display);
void				ft_rotate(t_stack **stack, char c, enum e_bol display);
void				ft_rotate_both(t_stack **a,
					t_stack **b, enum e_bol display);
char				**create_src(char **av);
int					check_src(char **src);
int					fill_stack(t_stack **stack, char **tab);
int					create_stack(char **tab, t_stack **a);
t_stack				*new_elem_stack(int nb);
void				add_elem(t_stack **stack, t_stack *der);
int					ft_size_stack(t_stack *stack);
void				free_elem_stack(t_stack **stack);
void				free_stack(t_stack **stack);
void				ft_swap_both(t_stack **a, t_stack **b, enum e_bol display);
void				ft_swap(t_stack **stack,
					char c, enum e_bol display);
void				ft_push(t_stack **src, t_stack **dest,
					char c, enum e_bol display);
void				apply_cmd(char *cmd, t_stack **a, t_stack **b);
int					ft_pos_min(t_stack *stack);
int					ft_max_nb(t_stack *stack);
int					ft_min_nb(t_stack *stack);
void				sort_five(t_stack **a, t_stack **b);
void				sort_three(t_stack **stack);
void				sort_push(t_stack **a, t_stack **b);
void				apply_strat(t_alg *stra, t_stack **a, t_stack **b);
void				last_rotates(t_stack **a);
void				pop(t_stack **a, t_stack **b);
int					get_pos_dest(int nb, t_stack **stack);
int					get_pos(int nb, t_stack **stack);
void				calc_b_cmd(t_stack **b, t_alg *rules, int nb);
void				calc_a_rev(t_stack **a, t_alg *rules, int pos);
void				calc_strat(t_alg *rules);
t_alg				*calc_opti(t_stack **a, t_stack **b);
void				get_to_top(t_stack **a, t_stack **b);
void				pop(t_stack **a, t_stack **b);
void				last_rotates(t_stack **a);
void				rules_init(t_alg **rules, t_alg **strat);
int					ft_pos_max(t_stack *stack);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	500
#endif
