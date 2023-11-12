/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:47:53 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/12 13:52:23 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eat(t_philo *philo)
{
	if (give_me_forks(philo))
		return ;
	// Talvez deva usar um mutex_lock aqui
	philo->meals_last = get_curr_time();
	philo->status = EAT;
	philo->meals_nbr--;
	// Talvez deva usar um mutex_unlock aqui
	msg_routine(philo, "is eating");
	lifetime_of_philo(philo, philo->data->time_eat);
	give_off_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	philo->status = SLEEP;
	msg_routine(philo, "is sleeping");
	lifetime_of_philo(philo, philo->data->time_sleep);
	usleep(100);
}

void	philo_think(t_philo *philo)
{
	philo->status == THINK;
	msg_routine(philo, "is thinking");
}

int	philo_end(t_philo *philo)
{
	// Talvez deva usar um mutex_lock aqui
	if ((get_curr_time() - philo->meals_last) >= philo->data->time_die)
	{
		if (!philo->data->end_philo)
			msg_routine(philo, "died");
		philo->data->end_philo = true;
		philo->status = DEAD;
		return (1);
	}
	// Caso use mutex, faça um "else" com o mutex_unlock
	return (0);
}

void	lifetime_of_philo(t_philo *philo, size_t time)
{
	long int	start_time;

	start_time = get_curr_time();
	while ((get_curr_time() - start_time) < time)
	{
		if (philo_end(philo))
			return ;
		usleep(10); // Se necessario faça ft_usleep
	}
}
