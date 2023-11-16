/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:30:45 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/15 17:18:50 by faaraujo         ###   ########.fr       */
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
	data->time_die = ft_atol(argv[2]);
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
	data->philo = malloc(sizeof(t_philo) * (data->nphilos));
	if (!(data->philo))
		return (3);
	return (0);
}

/**
 * @brief How the philo take the forks
 * @param pos position in the table
 * @param second_fork = [philo_position + 1] % nphilo
*/
void	init_philo(t_data *data)
{
	int		pos;

	pos = 0;
	while (pos < data->nphilos)
	{
		data->philo[pos].id = pos + 1;
		data->philo[pos].meals_nbr = data->ntimes_eat;
		data->philo[pos].status = THINK;
		data->philo[pos].data = data;
		data->philo[pos].meals_last = get_curr_time();
		data->philo[pos].first_fork = data->philo[pos].id - 1;
		data->philo[pos].second_fork = (data->philo[pos].id) % data->nphilos;
		pos++;
	}
}

/**
 * @brief How the philo take the forks
 * @param second_fork = [philo_position + 1] % nphilo 
*/
int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->mutex_msg, NULL))
		return (1);
	if (pthread_mutex_init(&data->mutex_end, NULL))
		return (2);
	data->forks = malloc(sizeof(t_fork) * data->nphilos);
	if (!(data->forks))
		return (3);
	while (i < data->nphilos)
	{
		if (pthread_mutex_init(&data->forks[i].mutex, NULL))
			return (4);
		data->forks[i].usable = 1;
		i++;
	}
	return (0);
}
