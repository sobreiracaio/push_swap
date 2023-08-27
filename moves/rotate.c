/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:04:28 by admin             #+#    #+#             */
/*   Updated: 2023/08/27 19:37:24 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int rotate(t_stack **stack)
{
    t_stack *head;
    t_stack *tail;
    
    if(ft_lstsize(*stack) < 2)
        return (-1);
    head = *stack;
    tail = ft_lstlast(head);
    *stack = head->next;
    head->next = NULL;
    tail->next = head;
    return (0);
    
}

int ra(t_stack **a)
{
    if(rotate(a) == -1)
        return (-1);
    write(1,"ra\n",3);
    return (0);
}

int rb(t_stack **b)
{
    if(rotate(b) == -1)
        return (-1);
    write(1,"rb\n",3);
    return (0);
}