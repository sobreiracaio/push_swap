/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 22:18:37 by admin             #+#    #+#             */
/*   Updated: 2023/08/29 19:13:30 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void error_message(char *msg, int size)
{
    write(2,msg,size);
    write(2,"\n",1);
    exit(EXIT_FAILURE);
}