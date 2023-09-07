/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:22:25 by admin             #+#    #+#             */
/*   Updated: 2023/09/07 17:48:11 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}t_stack;

void	check_args(int ac, char **av);
int		is_sorted(t_stack **stack);
int		check_size(char **args);

char	**ft_split(char const *s, char c);
t_stack	*ft_lstnew(int number);
t_stack	*ft_lstlast(t_stack *head);
void	ft_lstadd_back(t_stack **stack, t_stack *new);
int		ft_isdigit(int c);
long	ft_atoi(const char *nptr);
int		ft_lstsize(t_stack *lst);

void	error_message(void);
void	free_string(char **str);
void	free_stack(t_stack **stack);

void	index_stack(t_stack **stack);
int		index_distance_head(t_stack **stack, int index);
int		is_sorted(t_stack **stack);
int		get_min(t_stack **stack, int number);

void	simple_sort(t_stack **a, t_stack **b);
void	sort_3(t_stack **a);
void	radix_sort(t_stack **a, t_stack **b);

int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);

int		ra(t_stack **a);
int		rb(t_stack **b);
int		rr(t_stack **a, t_stack **b);

int		rra(t_stack **a);
int		rrb(t_stack **b);
int		rrr(t_stack **a, t_stack **b);

int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
#endif
