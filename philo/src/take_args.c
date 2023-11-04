/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:53:30 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/04 13:04:56 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_arg(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (check_arg(argv))
		return (2);
	return (0);
}

int	check_arg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv && argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @return Returns zero if false, non-zero if true   
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long int	ft_atol(const char *str)
{
	int			i;
	int			sig;
	long int	res;

	i = 0;
	sig = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		++i;
	}
	return (res * sig);
}

int	check_int_max(char **argv)
{
	int	i;

	i = 0;
	while (argv && argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}
