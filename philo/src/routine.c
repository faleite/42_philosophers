/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:10:50 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/13 17:34:43 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * 1. Wait all philos, start
 * 2. infinite loop philo
*/
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->nphilos == 1)
		error_case(philo->data, "UM PHILO");
	// FCT PARA APENAS UM PHILO 
	// loop infinito da routine (var dead p se alguem morrer)...
	while (philo->meals_nbr != 0)
	{
		// mutex_lock
		pthread_mutex_lock(&philo->data->mutex_end);
		if (philo->data->end_philo)
		{
			// mutex_unlock
			pthread_mutex_unlock(&philo->data->mutex_end);
			break ;
		}
		// mutex_unlock
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

/**
 * ACTUAL MEAL: criar mutex, criar threads, join threads, destroy mutex
 * 
 * ./philo 5 800 200 200 [5]
 * 1. if no meals, return [0];
 * 2. else if only one philo-> create a function
 * 3. else create all threads (philos)
 * 4. Create a monitor for thread (look if dies)
 * 5. Start the routine: pthread_create (for start race)
 * every philo start simultaneously
 * 6. join everyone
*/
void	start_meals(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	// init mutex p/ msg, meals, threads and forks;
	if (init_forks(data))
		return ;
	data->time_philos = get_curr_time();
	while (i < data->nphilos)
	{
		pthread_create(&philo[i].thread, NULL, routine, &philo[i]);
		i++;
	}
	i = 0;	
	while (i < data->nphilos)
	{
		pthread_join(philo[i++].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_msg);
	pthread_mutex_destroy(&data->mutex_eat);
	pthread_mutex_destroy(&data->mutex_end);
	i = 0;
	while (i < data->nphilos)
	{
		pthread_mutex_destroy(&data->forks[i].mutex);
		i++;
	}
}
