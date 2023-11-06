/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leite <leite@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:30:45 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/06 21:08:27 by leite            ###   ########.fr       */
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
	data->time_die = ft_atol(argv[2]) * 1000;
	data->time_eat = ft_atol(argv[3]) * 1000;
	data->time_sleep = ft_atol(argv[4]) * 1000;
	if (data->time_die < 60000
		|| data->time_eat < 60000
		|| data->time_sleep < 60000)
		return (2);
	if (argv[5])
		data->ntimes_eat = ft_atol(argv[5]);
	else
		data->ntimes_eat = -1;
	return (0);
}

/**
 * @brief How the philo take the forks
 * @param LEFT_FORK = [philo_position + 1] % nphilo
 * // static void
*/
void	catch_forks(t_philo *philo, t_fork *forks, int pos)
{
	int	num_philos;

	num_philos = philo->data->nphilos;
	philo->left_fork = &forks[(pos + 1) % num_philos];
	philo->right_fork = &forks[pos];
	if (!(philo->id % 2))
	{
		philo->left_fork = &forks[pos];
		philo->right_fork = &forks[(pos + 1) % num_philos];
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
		philo->meals_nbr = 0;
		philo->meals_max = false;
		philo->data = data;
		pos++;
	}
	catch_forks(philo, data->forks, pos);
}

/**
 * @brief How the philo take the forks
 * @param LEFT_FORK = [philo_position + 1] % nphilo 
*/
int	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->end_philos = false;
	data->start_philos = false;
	data->philos = malloc(sizeof(t_philo) * data->nphilos);
	use_fork(data->mutex, INIT);
	if (!(data->philos))
		return (1);
	data->forks = malloc(sizeof(t_fork) * data->nphilos);
	if (!(data->forks))
		return (2);
	while (i < data->nphilos)
	{
		if (use_fork(&data->forks[i].fork, INIT))
			return (3);
		data->forks[i].fork_id = i;
		i++;
	}
	init_philo(data);
	return (0);
}
