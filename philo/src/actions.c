/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:47:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/11 19:13:14 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eat(t_philo *philo)
{
	if (give_me_forks(philo))
		return ;
	philo->meals_last = get_curr_time();
	philo->status = EAT;
	philo->meals_nbr--;
	msg_routine(philo, "is eating");
	// verificar se time_eat acabou
	// soltar os garfos
}

void	philo_sleep(t_philo *philo)
{
	philo->status = SLEEP;
	msg_routine(philo, "is sleeping");
	// verificar se time_sleep acabou
	usleep(100);
}

void	philo_think(t_philo *philo)
{
	philo->status == THINK;
	msg_routine(philo, "is thinking");
}

void	msg_routine(t_philo *philo, char *msg)
{
	size_t	time;

	pthread_mutex_lock(philo->data->mutex);
	time = get_curr_time() - philo->data->time_philos;
	printf("%ld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->data->mutex);
}
