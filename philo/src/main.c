/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:07:26 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/08 16:52:28 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

int	main(int argc, char *argv[])
{
	t_data	data;

	if (take_arg(argc, argv))
		return (error_case(&data, "Invalid arguments"));
	if (put_arg(&data, argv))
		return (error_case(&data, "Enter a valid value"));
	if (init_data(&data))
		return (error_case(&data, "Init data not done"));
	// philo = malloc(sizeof(t_philo) * data->nphilos);
	// if (create_threads(philo))
		// return (3);
	// if (join_threads(philo))
		// return (4);
	return (0);
}
