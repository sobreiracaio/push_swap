/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:18:15 by admin             #+#    #+#             */
/*   Updated: 2023/08/28 19:32:26 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	push(t_stack **dest, t_stack **origin)
{
	t_stack	*temp;
	t_stack	*head_dest;
	t_stack	*head_orig;

	if (ft_lstsize(*origin) == 0)
		return (-1);
	head_dest = *dest;
	head_orig = *origin;
	temp = head_orig;
	head_orig = head_orig->next;
	*origin = head_orig;
	if (!head_dest)
	{
		head_dest = temp;
		head_dest->next = NULL;
		*dest = head_dest;
	}
	else
	{
		temp->next = head_dest;
		*dest = temp;
	}
	return (0);
}

int	pa(t_stack **a, t_stack **b)
{
	if (push(a, b) == -1)
		return (-1);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_stack **a, t_stack **b)
{
	if (push(b, a) == -1)
		return (-1);
	write(1, "pb\n", 3);
	return (0);
}
