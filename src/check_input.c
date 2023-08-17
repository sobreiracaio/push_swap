/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:46:29 by admin             #+#    #+#             */
/*   Updated: 2023/08/17 20:48:50 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int number_is_valid(char *str)
{
    int i;
    
    i = 0;
    if (str[i] == '+' || str[i] == '-')
        str[i++];
    while (str[i] >= '0' && str[i] <= '9')
        str[i++];
    if (str[i] && !(str[i] >= '0' && str[i] <= '9'))
        return (0);
    if (!str[i] && ((str[i-1] == '+' || str[i-1] == '-')))
        return (0);
    return (1);
}

static char *remove_extra_zeros(char *str)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    if(str[i] == '+' || str[i] == '-')
        i++;
    while(str[i] == '0')
        i++;
    if(!str[i])
    {
        str[0] = '0';
        str[1] = '\0';
        return (str);
    }
    else
    {
        if (str[0] == '-')
            str[j++] = '-';
        while(str[i])
            str[j++] = str[i++];
        str[j] = '\0';
        return (str);
    }
}

static int check_doubles (char **arg)
{
    int i;
    int j;
    
    i = 1;
    while (arg[i])
    {
        j = i + 1;
        while(arg[j])
        {
            if (ft_strcmp(arg[i], arg[j]) == 0)
                return (i);
            j++;
        }
        i++;
    }
    return (0);
}


int check_input(char **arg)
{
    int i; 

    i = 1;
    while(arg[i])
    {
        if(!number_is_valid(arg[i]))
            return (0);
        if(arg[i][0] == '0' || arg[i][0] == '0')
            arg[i] = remove_extra_zeros(arg[i]);
        i++;
    }
    if(check_doubles(arg) || !arg[1][0])
        return (0);
    return (1);
}