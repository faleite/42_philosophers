/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:55:38 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/04 20:29:59 by faaraujo         ###   ########.fr       */
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
int	error_case(t_data *data, int ret)
{
	printf("Error(%d)\n", ret);
	free(data);
	return (1);
}

/**
 * @brief FOR USE MUTEX
 * @param init
 * @param destroy
 * @param lock
 * @param unlock
*/
int	use_fork(pthread_mutex_t *mutex, t_operator op)
{
	int	status;

	status = 0;
	if (op == LOCK)
		status += pthread_mutex_lock(mutex);
	else if (op == UNLOCK)
		status += pthread_mutex_unlock(mutex);
	else if (op == INIT)
		status += pthread_mutex_init(mutex, NULL);
	else if (op == DESTROY)
		status += pthread_mutex_destroy(mutex);
	return (status);
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

/*
int	mutex_error_case(int status, t_operator op)
{
	if (status == 0)
		return (0);
	if (status == EINVAL && (op == LOCK || op == UNLOCK))
		return (EINVAL);
	else if (status == EINVAL && op == INIT)
		return (EINVAL);
	else if (status == EDEADLK)
		return (EDEADLK);
	else if (status == EPERM)
		return (EPERM);
	else if (status == ENOMEM)
		return (ENOMEM);
	else if (status == EBUSY)
		return (EBUSY);
}
*/
