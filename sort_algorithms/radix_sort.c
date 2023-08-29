/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:18:13 by admin             #+#    #+#             */
/*   Updated: 2023/08/28 22:52:11 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int get_max_bits(t_stack **stack)
{
    t_stack *head;
    int max;
    int max_bits;
    
    head = *stack;
    max = head->index;
    max_bits = 0;
    while(head)
    {
        if(head->index > max)
            max = head->index;
        head = head->next;
    }
    while((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void radix_sort (t_stack **a, t_stack **b)
{
    t_stack *head_a;
    int i;
    int j;
    int size;
    int max_bits;

    i = 0;
    head_a = *a;
    size = ft_lstsize(*a);
    max_bits = get_max_bits(a);
    while(i < max_bits)
    {
        j =0;
        while (j++ < size)
        {
            head_a = *a;
            if(((head_a->index >> i) & 1) == 1)
                ra(a);
            else
                pb(a, b);
        }
        while(ft_lstsize(*b) != 0)
            pa(a, b);
        i++;
        
    }
}