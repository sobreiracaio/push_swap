/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:39:10 by admin             #+#    #+#             */
/*   Updated: 2023/08/23 22:49:58 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



static int is_doubled(int nbr, char **av, int i)
{
    i++;
    while(av[i])
    {
        if(ft_atoi(av[i]) == nbr)
            return (1);
        i++;
    }
    return (0);
}

static int is_num(char *nbr)
{
    int i;

    i = 0;
    if(nbr[0] == '-' || nbr[0] == '+')
        i++;
    if((nbr[0] == '-' || nbr[0] == '+') && !nbr[1])
        return (0);
    while(nbr[i])
    {
        if(!ft_isdigit(nbr[i]))
            return (0);
        i++;
    }
    return (1);
    
}

void check_args(int ac, char **av)
{
    int i;
    long temp;
    char **args;
    
    i =1;
    if (ac == 2)
        args = split_args(av[1]);
    else
        args = av;
    while(args[i])
    {
        temp = ft_atoi(args[i]);
        if(!is_num(args[i]))
            error_message("Error: No valid numbers among the arguments." , 45);
        if(is_doubled(temp, args, i) == 1)
            error_message("Error: No duplicated numbers allowed.", 26);
        if(temp < INT_MIN || temp > INT_MAX)
            error_message("Error: Number beyond INT limits.", 29);
        i++;
    }
    if(ac == 2)
        free_string(args);
}