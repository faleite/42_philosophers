/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:10:50 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/08 16:52:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * 1. Wait all philos, start
 * 2. infinite loop philo
*/
// void	*routine(void *arg)
// {
	// ver se e um philo fct para um philo
	// loop infinito da routine (var dead p se alguem morrer) (fct para dead) *sleep(100)
	// t_philo	*philo;

	// philo = (t_philo *)arg;
// }

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
// void	start_meals(t_data *data)
// {
// 	int	i;

// 	i = 0;
	//if (!data->ntimes_eat) // maybe == -1
	//	return ;
	//if (data->nphilos == 1)
		; // TODO agarra o garfo ate acabar o tempo (bloquea a thread) ou tentar agarrar os dois garfos ate morrer
	//init mutex p/ msg, meals, threads and forks;
	//start_time() tempo que comecou
	//else
	// {
	// 	while (i < data->nphilos)
	// 		use_thread(&data->philos[i].id, routine, &data->philos[i], CREATE);
	// 	i++;
	// }
	// while () para join;
	//fct destroy all mutex:
// }
