/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 23:08:12 by admin             #+#    #+#             */
/*   Updated: 2023/08/28 22:35:14 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int index_distance_head(t_stack **stack, int index)
{
    t_stack *head;
    int distance;
    
    while(head)
    {
        if(head->index == index)
            break;
        distance++;
        head = head->next;
    }
    return(distance);
}

int get_min (t_stack **stack, int number)
{
    t_stack *head;
    int min;
    head = stack;
    min = head->index;
    while(head->next)
    {
        head = head->next;
        if((head->index < min) && head->index != number)
            min = head->index;
    }
    return (min);
}

static t_stack *get_next_min(t_stack **stack)
{
    t_stack *head;
    t_stack *min;
    int found_min;

    head = *stack;
    min = NULL;
    found_min = 0;

    if(head)
    {
        while (head)
        {
            if((head->index == -1) && (!found_min || head->number < min->number))
            {
                min = head;
                found_min = 1;
            }
            head = head->next;
        }
        
        
    }
    return (min);
}

void index_stack(t_stack **stack)
{
    t_stack *head;
    int index;
    
    index = 0;
    head = get_next_min(stack);
    while(head)
    {
        head->index = index++;
        head = get_next_min(stack);
    }
}

int is_sorted (t_stack **stack)
{
    t_stack *s;
    
    s = *stack;
    while(s && s->next)
    {
        if(s->number > s->next->number)
            return (0);
        s = s->next;
    }
    return (1);
}