/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:22:12 by admin             #+#    #+#             */
/*   Updated: 2023/08/23 23:08:33 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


int main(int ac, char **av)
{
    t_stack **sa;
    t_stack **sb;

    if (ac < 2)
        return (-1);
    check_args(ac, av);
    sa = (t_stack **)malloc(sizeof(t_stack));
    *sa = NULL;
    if(is_sorted(sa) == 1);
        exit(EXIT_SUCCESS);
    
}