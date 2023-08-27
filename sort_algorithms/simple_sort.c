/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:07:11 by admin             #+#    #+#             */
/*   Updated: 2023/08/27 17:34:22 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void simple_sort(t_stack **a, t_stack **b)
{
    int size;
    
    if(is_sorted(a) || ft_lstsize(*a) == 0 || ft_lstsize(*a) == 1)
        return;
    if(size == 2)
        sa(a);
    else if(size == 3)
        sort_3(a);
}