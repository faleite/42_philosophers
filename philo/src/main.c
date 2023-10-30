/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:07:26 by faaraujo          #+#    #+#             */
/*   Updated: 2023/10/30 21:47:03 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	put_arg(t_data *data, int argc, char **argv)
{
	data->philos = ft_atoi(argv[1]);
	data->forks = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->ntimes_eat = ft_atoi(argv[5]);
}

void	*routine(void *arg)
{
	(void)arg;
	printf("Hello from threads\n");

	return (NULL);
}

int	create_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->philos)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, NULL) != 0) // routine sem &
			return (1);
	}
	return (0);
}

int	join_threads(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->philos)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	t_philo	*philo;

	data = malloc(sizeof(t_data));
	philo = malloc(sizeof(t_philo) * data->philos);
	if (take_arg(argc, argv))
		return (1);
	put_arg(data, argc, argv);
	if (create_threads(data, philo))
		return (1);
	if (join_threads(data, philo))
		return (1);
	return (0);
}

// void	init_philo(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < data->philos)
// 	{
		
// 	}
// }