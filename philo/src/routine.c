/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:10:50 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/08 21:19:21 by faaraujo         ###   ########.fr       */
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
	// ver se e um philo fct para um philo
	// loop infinito da routine (var dead p se alguem morrer)...
	// (fct para dead) *sleep(100)
	if (philo->status == THINK)
		philo_eat(philo);
	else if (philo->status == EAT)
		philo_sleep(philo);
	else if (philo->status == SLEEP)
		philo_think(philo);
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
int	start_meals(t_data *data)
{
	int	i;

	i = 0;
	// if (!data->ntimes_eat) // maybe == -1
	// 	return (1);
	if (data->nphilos == 1)
		return (2); // TODO agarra o garfo ate acabar o tempo (bloquea a thread) ou tentar agarrar os dois garfos ate morrer
	// init mutex p/ msg, meals, threads and forks;
	if (use_fork(data->mutex, INIT))
		return (3);
	data->time_philos = get_timestamp();
	while (i < data->nphilos)
		use_thread(&data->philos[i++].id, routine, &data->philos[i], CREATE);
	i = 0;
	while (i < data->nphilos)
		use_thread(data->philos[i++].id, NULL, NULL, JOIN);
	// fct destroy all mutex:
	if (use_fork(data->mutex, DESTROY))
		return (4);
}
