/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:13:38 by admin             #+#    #+#             */
/*   Updated: 2023/08/21 19:10:05 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"



int main (int ac, char **av)
{
    int size;
    t_stack *a;
    t_stack *b;

    if (ac < 2)
        return (0);
    if(!check_input(av))
        print_error();
    a = create_stack(ac, av);
    b = NULL;
    size = stack_len(a);
    
    
    
    
    
}