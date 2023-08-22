/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:29:59 by admin             #+#    #+#             */
/*   Updated: 2023/08/21 20:35:03 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void get_main_index(t_stack *sa, int size)
{
    t_stack *a;
    t_stack *max_address;
    int max_nbr;
    
    while(size--)
    {
        a = sa;
        max_nbr = INT_MIN;
        max_address = NULL;
        while(a)
        {
            if(a->nbr == INT_MIN && a->main_index == 0)
                a->main_index = 1;
            else if(a->nbr > max_nbr && a->main_index == 0)
            {
                max_nbr = a->nbr;
                max_address = a;
                a = sa;
            }
            else
                a = a->next;
        }
        if(max_address)
            max_address->main_index = size +1;
    }
}

int stack_len(t_stack *stack)
{
    int size;
    t_stack *s;
    
    size = 0;
    s = stack;
    while(s)
    {
        size++;
        s = s->next;
    }
    return (size);
}

static t_stack *new_node(int nbr)
{
    t_stack *stack;
    stack = (t_stack *)malloc(sizeof(t_stack));
    if(!stack)
        return (NULL);
    stack->nbr = nbr;
    stack->main_index = 0;
    stack->position = -1;
    stack->where_fit = -1;
    stack->mv_a = -1;
    stack->mv_b = -1;
    stack->next = NULL;
    return (stack); 
}

t_stack *create_stack(int ac, char **av)
{
    t_stack *sa;
    long int nbr;
    int i ;

    sa = NULL;
    nbr = 0;
    i = 1;
    while (i < ac)
    {
        nbr = ft_atoi(av[i]);
        if (nbr < INT_MIN || nbr > INT_MAX)
            return 0;
        if (i == 1)
            sa = new_node((int)nbr);
        else
            add_at_end(&sa, new_node((int)nbr));
        i++;
    }
    return (sa);
}
