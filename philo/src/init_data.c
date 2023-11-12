/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:30:45 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/12 19:04:41 by faaraujo         ###   ########.fr       */
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
	data->end_philo = false;
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
int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	// if (pthread_mutex_init(&data->mutex, NULL))
	// 	return (1);
	if (pthread_mutex_init(&data->mutex_msg, NULL))
		return (1);
	if (pthread_mutex_init(&data->mutex_eat, NULL))
		return (1);
	if (pthread_mutex_init(&data->mutex_end, NULL))
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
		philo->second_fork = (philo->id) % num_philos; // &forks[(pos + 1) % num_philos];
	}
	else
	{
		philo->first_fork = (philo->id) % num_philos;
		philo->second_fork = philo->id - 1;
	}
}

/**
 * @param pos position in the table
 * // static void
*/
void	init_philo(t_philo *philo, t_data *data)
{
	int		pos;

	pos = 0;
	while (pos < data->nphilos)
	{
		philo[pos].id = pos + 1;
		philo[pos].meals_nbr = data->ntimes_eat;
		philo[pos].status = THINK;
		philo[pos].data = data;
		philo[pos].meals_last = get_curr_time();
		philo[pos].first_fork = philo[pos].id - 1;
		philo[pos].second_fork = (philo[pos].id) % data->nphilos;
		//order_forks(philo);
		pos++;
	}
}
