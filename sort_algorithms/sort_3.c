/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:37:56 by admin             #+#    #+#             */
/*   Updated: 2023/08/28 22:46:57 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_231(t_stack **a, t_stack *head, int min)
{
	if (head->next->index == min)
		sa(a);
	else
		rra(a);
}

static void	sort_132(t_stack **a)
{
	ra(a);
	sa(a);
	rra(a);
}

static void	sort_312(t_stack **a, t_stack *head, int min)
{
	if (head->next->index == min)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

void	sort_3(t_stack **a)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = *a;
	min = get_min(a, -1);
	next_min = get_min(a, min);
	if (is_sorted(a) == 1)
		return ;
	if (head->index == min && head->next->index != next_min)
		sort_132(a);
	else if (head->index == next_min)
		sort_231(a, head, min);
	else
		sort_312(a, head, min);
}
