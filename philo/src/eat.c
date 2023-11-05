/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:10:50 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/05 09:48:28 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * @name ACTUAL MEAL
 * @example ./philo 5 800 200 200 [5]
 * 1. if no meals, return [0];
 * 2. else if only one philo->
 * 3. else create all threads (philos)
 *   4. Create a monitor for thread (look if dies)
 *   5. Start the routine: pthread_create (for start race)
 *    every philo start simultaneously
 *   6. join everyone
*/
void	start_meals(t_data *data)
{
	int	i;

	i = 0;
	if (!data->ntimes_eat) // maybe == -1
		return ;
	else if (data->nphilos == 1)
		; // TODO
	else
	{
		while (i < data->nphilos)
			use_thread(&data->philos[i].id, routine, &data->philos[i], CREATE);
	}
}
