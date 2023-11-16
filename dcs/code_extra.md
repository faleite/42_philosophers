```c
/**
 * THREAD ERRORS
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
```

```c
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
```

### Simple test of the philo
```c
void	*routine(void *arg)
{
	(void)arg;
	printf("Hello from threads\n");
	return (NULL);
}

int	create_threads(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->nphilos)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, NULL) != 0) // routine sem &
			return (1);
	}
	return (0);
}

int	join_threads(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->nphilos)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (1);
	}
	return (0);
}
```

### Version of the sleep function a little better
```c
int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_curr_time();
	while ((get_curr_time() - start) < milliseconds)
		usleep(100);
	return (0);
}
```