/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:22:12 by admin             #+#    #+#             */
/*   Updated: 2023/09/08 17:39:21 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_size(char **args)
{
	int		size;

	size = 0;
	while (args[size] != NULL)
		size++;
	if (size <= 1)
	{
		free_string(args);
		error_message();
	}
	return (0);
}

static void	sort_stack(t_stack **sa, t_stack **sb)
{
	if(is_sorted(sa) == 0)
	{
	if (ft_lstsize(*sa) <= 5)
		simple_sort(sa, sb);
	else
		radix_sort(sa, sb);
	}
}

static void	create_stack(t_stack **stack, int ac, char **av)
{
	t_stack	*new;
	char	**args;
	int		i;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (ac == 2)
		free_string(args);
}

int	main(int ac, char **av)
{
	t_stack	**sa;
	t_stack	**sb;

	if (ac < 2)
		return (0);
	check_args(ac, av);
	sa = (t_stack **)malloc(sizeof(t_stack));
	*sa = NULL;
	create_stack(sa, ac, av);
	sb = (t_stack **)malloc(sizeof(t_stack));
	*sb = NULL;
	sort_stack(sa, sb);
	free_stack(sa);
	free_stack(sb);
	return (0);
}
