/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:01:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/11 19:07:41 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	unlock_forks(t_philo *philo, int value)
{
	int	first;
	int	second;

	first = philo->first_fork;
	second = philo->second_fork;
	philo->data->forks[first].usable = value;
	philo->data->forks[second].usable = value;
	pthread_mutex_unlock(&philo->data->forks[first].mutex);
	pthread_mutex_unlock(&philo->data->forks[second].mutex);
}

int	odd_even(t_philo *philo, int first_fork, int second_fork)
{
	pthread_mutex_lock(&philo->data->forks[first_fork].mutex);
	if (!philo->data->forks[first_fork].usable)
		return (not_usable(philo, first_fork));
	pthread_mutex_lock(&philo->data->forks[second_fork].mutex);
	if (!philo->data->forks[second_fork].usable)
	{
		pthread_mutex_unlock(&philo->data->forks[first_fork].mutex);
		return (not_usable(philo, second_fork));
	}
	msg_routine(philo, "has taken a fork");
	msg_routine(philo, "has taken a fork");
	return (0);
}

int	give_me_forks(t_philo *philo)
{
	int	first;
	int	second;

	first = philo->first_fork;
	second = philo->second_fork;
	if (philo->id % 2)
	{
		if (odd_even(philo, first, second))
			return (1);
	}
	else
	{
		if (odd_even(philo, second, first))
			return (2);
	}
	unlock_forks(philo, 0);
	return (0);
}

void	give_off_forks(t_philo *philo)
{
	int	first;
	int	second;

	first = philo->first_fork;
	second = philo->second_fork;
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->data->forks[first].mutex);
		pthread_mutex_lock(&philo->data->forks[second].mutex);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[second].mutex);
		pthread_mutex_lock(&philo->data->forks[first].mutex);
	}
	unlock_forks(philo, 1);
}
