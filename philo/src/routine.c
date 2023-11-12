/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:10:50 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/12 14:31:03 by faaraujo         ###   ########.fr       */
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
	// FCT PARA APENAS UM PHILO 
	// loop infinito da routine (var dead p se alguem morrer)...
	while (philo->meals_nbr != 0)
	{
		// mutex_lock
		if (philo->data->end_philo)
			// mutex_unlock
			break ;
		// mutex_unlock
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
void	start_meals(t_data *data)
{
	int	i;

	i = 0;
	// init mutex p/ msg, meals, threads and forks;
	if (init_data(data))
		return ;
	data->time_philos = get_curr_time();
	while (i < data->nphilos)
		pthread_create(&data->philos[i++].id, NULL, routine, &data->philos[i]);
	i = 0;
	while (i < data->nphilos)
		pthread_join(data->philos[i++].id, NULL);
	pthread_mutex_destroy(&data->mutex);
	i = 0;
	while (i < data->nphilos)
		pthread_mutex_destroy(&data->forks[i++].mutex);
}
