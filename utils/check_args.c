/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 23:04:04 by admin             #+#    #+#             */
/*   Updated: 2023/09/11 23:21:39 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (*s1 == '+')
	{
		if (*s2 != '+')
			s1++;
	}
	else
	{
		if (*s2 == '+')
			s2++;
	}
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int	is_repeated(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = i + 1;
		while (arg[j])
		{
			if (ft_strcmp(arg[i], arg[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_valid_number(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s && !(*s >= '0' && *s <= '9'))
		error_message();
	if (!*s && (*(s - 1) == '+' || *(s - 1) == '-'))
		error_message();
	return (1);
}

static char	*remove_extra_zeros(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	if (!s[i])
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	else
	{
		if (s[0] == '-')
			s[j++] = '-';
		while (s[i])
			s[j++] = s[i++];
		s[j] = '\0';
		return (s);
	}
}

int	check_args(char **arg)
{
	int	i;
	long temp;

	i = 1;
	while (arg[i])
	{
		temp = ft_atoi(arg[i]);
		if (!is_valid_number(arg[i]))
			error_message();
		if (temp < INT_MIN || temp > INT_MAX)
			error_message();
		if (arg[i][0] == '0' || arg[i][1] == '0')
			arg[i] = remove_extra_zeros(arg[i]);
		i++;
	}
	if (is_repeated(arg) || !arg[1][0])
		error_message();
	return (1);
}