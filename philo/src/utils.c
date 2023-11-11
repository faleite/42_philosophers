/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:55:38 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/11 19:08:47 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * Errors
 * 
 * On success returns 0;
 * 
 * The pthread_mutex_destroy() function may fail if:
 * EBUSY
 * The implementation has detected an attempt to destroy the object referenced
 * by mutex while it is locked or referenced (for example, while being used in
 * a pthread_cond_timedwait() or pthread_cond_wait()) by another thread.
 * EINVAL
 * The value specified by mutex is invalid.
 * 
 * The pthread_mutex_init() function shall fail if:
 * EAGAIN
 * The system lacked the necessary resources (other than memory) to initialize
 * another mutex.
 * ENOMEM
 * Insufficient memory exists to initialize the mutex.
 * EPERM
 * The caller does not have the privilege to perform the operation.
 * 
 * The pthread_mutex_init() function may fail if:
 * EBUSY
 * The implementation has detected an attempt to reinitialize the object
 * referenced by mutex, a previously initialized, but not yet destroyed, mutex.
 * EINVAL
 * The value specified by attr is invalid.
 * 
 * pthread_join() function may fail if:
 * EDEADLK
 * A deadlock was detected (e.g., two threads tried to join with each other);
 * or thread specifies the calling thread.
 * EINVAL
 * thread is not a joinable thread.
 * EINVAL
 * Another thread is already waiting to join with this thread.
 * ESRCH
 * No thread with the ID thread could be found.
*/
int	error_case(t_data *data, char *msg)
{
	printf("Error\n%s\n", msg);
	if (!(data))
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
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/**
 * @brief FOR USE THREAD (PHILO)
 * @param create
 * @param join
 * @param detach
*/
int	use_thread(pthread_t *thread, void *(*foo)(void *),
	void *data, t_operator op)
{
	int	status;

	status = 0;
	if (op == CREATE)
		status += pthread_create(thread, NULL, foo, data);
	else if (op == JOIN)
		status += pthread_join(*thread, NULL);
	else if (op == DETACH)
		status += pthread_detach(*thread);
	return (status);
}
