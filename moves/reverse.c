/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:11:11 by admin             #+#    #+#             */
/*   Updated: 2023/08/28 21:41:32 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int reverse(t_stack **stack)
{
    t_stack *head;
    t_stack *tail;

    if(ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    tail = ft_lstlast(head);
    
    while(head)
    {
        if(head->next->next == NULL)
        {
            head->next = NULL;
            break;
        }
        head = head->next;
    }
    tail->next = *stack;
    *stack = tail;
    return (0);
}

int rra(t_stack **a)
{
    if(reverse(a) == -1)
        return (-1);
    write(1,"rra\n",4);
    return (0);
}

int rrb(t_stack **b)
{
    if(reverse(b) == -1)
        return (-1);
    write(1,"rrb\n",4);
    return (0);
}

int	rrr(t_stack **a, t_stack **b)
{
	if ((ft_lstsize(*a) < 2) || (ft_lstsize(*b) < 2))
		return (-1);
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
	return (0);
}