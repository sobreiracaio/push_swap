/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:11:15 by admin             #+#    #+#             */
/*   Updated: 2023/09/05 18:56:15 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		temp_nbr;
	int		temp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		error_message();
	temp_nbr = head->number;
	temp_index = head->index;
	head->number = next->number;
	head->index = next->index;
	next->number = temp_nbr;
	next->index = temp_index;
	return (0);
}

int	sa(t_stack **a)
{
	if (swap(a) == -1)
		return (-1);
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_stack **b)
{
	if (swap(b) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_stack **a, t_stack **b)
{	
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	return (0);
}
