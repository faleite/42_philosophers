/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:55:38 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/14 21:36:17 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	msg_routine(t_philo *philo, char *msg)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->mutex_msg);
	time = get_curr_time() - philo->data->time_philos;
	printf("%ld %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->mutex_msg);
}

int	error_case(t_data *data, char *msg)
{
	printf("Error\n%s\n", msg);
	if (!data)
		free(data);
	return (1);
}

int	not_usable(t_philo *philo, int fork)
{
	pthread_mutex_unlock(&philo->data->forks[fork].mutex);
	if (philo->status != THINK)
		msg_routine(philo, "is thinking");
	philo->status = THINK;
	return (1);
}

size_t	get_curr_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		printf("Error\n gettimeofday()\n");
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

// Version of the sleep function a little better
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_curr_time();
	while ((get_curr_time() - start) < milliseconds)
		usleep(100);
	return (0);
}
