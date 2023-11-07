/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: correia <correia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:48:09 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/19 09:26:58 by correia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_eat(t_philo *philo)
{
	if (pick_up_fork(philo) == 1)
		return ;
	pthread_mutex_lock(&philo->data->mutex_meal);
	philo->last_eat = get_timestamp();
	philo->state = EAT;
	philo->n_eaten--;
	pthread_mutex_unlock(&philo->data->mutex_meal);
	print_msg(philo, "is eating");
	action_philo(philo, philo->data->time_to_eat);
	drop_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	philo->state = SLEEP;
	print_msg(philo, "is sleeping");
	action_philo(philo, philo->data->time_to_sleep);
	usleep(100);
}

void	philo_think(t_philo *philo)
{
	philo->state = THINK;
	print_msg(philo, "is thinking");
}

int	philo_is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_dead);
	if ((get_timestamp() - philo->last_eat) >= philo->data->time_to_die)
	{
		if (philo->data->dead == 1)
			print_msg(philo, "died");
		philo->data->dead = 0;
		philo->state = DEAD;
		pthread_mutex_unlock(&philo->data->mutex_dead);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->mutex_dead);
		return (0);
	}
}

void	action_philo(t_philo *philo, size_t time)
{
	long int	start_time;

	start_time = get_timestamp();
	while ((get_timestamp() - start_time) < time)
	{
		if (philo_is_dead(philo))
		{
			return ;
		}
		usleep(10);
	}
}
