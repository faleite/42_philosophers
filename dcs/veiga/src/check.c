/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:07:06 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/19 15:50:26 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_args(int ac, char **av)
{
	if (check_ac(ac) == 1)
		return (1);
	if (is_digit(ac, av) == 1)
		return (1);
	if (check_av(ac, av) == 1)
		return (1);
	return (0);
}

int	check_ac(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error: Wrong amount of arguments\n");
		printf("./philo\n");
		printf("[1] number_of_philosophers\n");
		printf("[2] time_to_die\n");
		printf("[3] time_to_eat\n");
		printf("[4] time_to_sleep\n");
		printf("[5] [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	return (0);
}

int	check_av(int ac, char **av)
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;

	number_of_philos = ft_atoi(av[1]);
	time_to_die = ft_atoi(av[2]);
	time_to_eat = ft_atoi(av[3]);
	time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	else
		number_of_times_each_philosopher_must_eat = 0;
	if (number_of_philos < 1 || number_of_philos > 200 || time_to_die < 60
		|| time_to_eat < 60 || time_to_sleep < 60
		|| number_of_times_each_philosopher_must_eat < 0)
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	return (0);
}
