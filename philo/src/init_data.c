/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:30:45 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/12 15:14:16 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 *            ms  ms  ms 
 * ./philo 5 800 200 200 [5]
*/
int	put_arg(t_data *data, char **argv)
{
	if (check_int_max(argv))
		return (1);
	data->nphilos = ft_atol(argv[1]);
	data->time_die = ft_atol(argv[2]); // * 1000 put in function time
	data->time_eat = ft_atol(argv[3]);
	data->time_sleep = ft_atol(argv[4]);
	if (argv[5])
		data->ntimes_eat = ft_atol(argv[5]);
	else
		data->ntimes_eat = -1;
	if (data->nphilos < 1 || data->nphilos > 200
		|| data->time_die < 60
		|| data->time_eat < 60
		|| data->time_sleep < 60)
		return (2);
	return (0);
}

/**
 * @brief How the philo take the forks
 * @param second_fork = [philo_position + 1] % nphilo 
*/
int	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->end_philo = false;
	data->start_philos = false; // Nao esta usando ainda
	data->philos = malloc(sizeof(t_philo) * data->nphilos);
	if (!(data->philos))
		return (1);
	data->forks = malloc(sizeof(t_fork) * data->nphilos);
	if (!(data->forks))
		return (2);
	while (i < data->nphilos)
	{
		if (pthread_mutex_init(&data->forks[i].mutex, NULL))
			return (3);
		data->forks[i].usable = 1;
		i++;
	}
	init_philo(data);
	return (0);
}

/**
 * @brief How the philo take the forks
 * @param second_fork = [philo_position + 1] % nphilo
 * // static void
*/
void	order_forks(t_philo *philo)
{
	int	num_philos;

	num_philos = philo->data->nphilos;
	if (!(philo->id % 2))
	{
		philo->first_fork = philo->id - 1; // &forks[pos];
		philo->second_fork = (philo->id) & num_philos; // &forks[(pos + 1) % num_philos];
	}
	else
	{
		philo->first_fork = (philo->id) & num_philos;
		philo->second_fork = philo->id - 1;
	}
}

/**
 * @param pos position in the table
 * // static void
*/
void	init_philo(t_data *data)
{
	int		pos;
	t_philo	*philo;

	pos = 0;
	while (pos < data->nphilos)
	{
		philo = data->philos + pos;
		philo->id = pos + 1;
		philo->meals_nbr = data->ntimes_eat;
		philo->status = THINK;
		philo->data = data;
		order_forks(philo);
		pos++;
	}
}
