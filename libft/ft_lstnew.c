/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:44:51 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/09/01 19:57:18 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_lstnew(int number)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->number = number;
	node->index = -1;
	node->next = NULL;
	return (node);
}
