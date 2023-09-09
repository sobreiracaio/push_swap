/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:39:10 by admin             #+#    #+#             */
/*   Updated: 2023/09/09 17:15:20 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	has_alpha(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if ((args[i] >= '0' && args[i] <= '9') || args [i] == ' '
			|| args[i] == '+' || args[i] == '-')
			i++;
		else
			error_message();
	}
}

static int	is_doubled(int nbr, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == nbr)
			return (1);
		i++;
	}
	return (0);
}

static int	is_num(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[0] == '-' || nbr[0] == '+')
	{
		i++;
	}
	if ((nbr[0] == '-' || nbr[0] == '+') && !nbr[1])
	{
		return (0);
	}
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	check_args(int ac, char **av)
{
	int		i;
	long	temp;
	char	**args;

	i = 1;
	if (ac == 2)
	{
		has_alpha(av[1]);
		args = ft_split(av[1], ' ');
	}
	else
		args = av;
	check_size(args);
	while (args[i])
	{
		temp = ft_atoi(args[i]);
		if (!is_num(args[i]) || is_doubled(temp, args, i) == 1)
			error_message();
		if (temp < INT_MIN || temp > 2147483647)
			error_message();
		i++;
	}
	if (ac == 2)
		free_string(args);
}
