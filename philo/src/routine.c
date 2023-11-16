/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:10:50 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/15 17:49:44 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	one_philo(t_philo *philo);

void	start_meals(t_data *data)
{
	int	i;

	i = -1;
	if (init_forks(data))
		return ;
	data->time_philos = get_curr_time();
	while (++i < data->nphilos)
		pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]);
	i = -1;
	while (++i < data->nphilos)
		pthread_join(data->philo[i].thread, NULL);
	i = -1;
	pthread_mutex_destroy(&data->mutex_msg);
	pthread_mutex_destroy(&data->mutex_end);
	while (++i < data->nphilos)
		pthread_mutex_destroy(&data->forks[i].mutex);
}

/**
 * 1. Wait all philos, start
 * 2. infinite loop philo
*/
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nphilos == 1)
		one_philo(philo);
	while (philo->meals_nbr != 0)
	{
		pthread_mutex_lock(&philo->data->mutex_end);
		if (philo->data->end_philo)
		{
			pthread_mutex_unlock(&philo->data->mutex_end);
			break ;
		}
		pthread_mutex_unlock(&philo->data->mutex_end);
		if (philo_end(philo))
			break ;
		if (philo->status == THINK)
			philo_eat(philo);
		else if (philo->status == EAT)
			philo_sleep(philo);
		else if (philo->status == SLEEP)
			philo_think(philo);
	}
	return (NULL);
}

static void	one_philo(t_philo *philo)
{
	msg_routine(philo, "is thinking");
	usleep(philo->data->time_die * 1000);
}
