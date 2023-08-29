/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:07:11 by admin             #+#    #+#             */
/*   Updated: 2023/08/28 22:51:36 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_4(t_stack **a, t_stack **b)
{
    int distance;
    
    if(is_sorted(a))
        return;
    distance = index_distance_head(a,get_min(a, -1));
    if(distance == 1)
        ra(a);
    else if(distance == 2)
    {
        ra(a);
        ra(a);
    }
    else if (distance == 3)
        rra(a);
    if(is_sorted(a))
        return;
    pb(a, b);
    sort_3(a);
    pa(a, b);
    
    
}

void sort_5(t_stack **a, t_stack **b)
{
    int distance;
    
    distance = index_distance_head(a,get_min(a, -1));
    if (distance == 1)
        ra(a);
    else if(distance == 2)
    {
        ra(a);
        ra(a);
    }
    else if(distance == 3)
    {
        rra(a);
        rra(a);
    }
    else if (distance == 4)
        rra(a);
    if (is_sorted(a))
        return;
    pb(a, b);
    sort_4(a, b);
    pa(a,b);
}

void simple_sort(t_stack **a, t_stack **b)
{
    int size;
    
    if(is_sorted(a) || ft_lstsize(*a) == 0 || ft_lstsize(*a) == 1)
        return;
    size = ft_lstsize(*a);
    if(size == 2)
        sa(a);
    else if(size == 3)
        sort_3(a);
    else if (size == 4)
        sort_4(a, b);
    else if(size == 5)
        sort_5(a, b);
}