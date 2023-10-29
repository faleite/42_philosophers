/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:07:26 by faaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 16:34:20 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	put_arg(t_data *data, char **argv)
{
	data->philos = ft_atoi(argv[1]);
	data->forks = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->ntimes_eat = ft_atoi(argv[5]);
}

void	*routine(void *arg)
{
	(void)arg;
	printf("Hello from threads\n");

	return (NULL);
}

int	create_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos)
	{
		if (pthread_create(&data->thread[i], NULL, &routine, NULL))
			return (1);
	}
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos)
	{
		if (pthread_join(data->thread[i], NULL))
			return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (take_arg(argc, argv))
		return (1);
	put_arg(data, argv);
	printf("Philos: %d\n", data->philos);
	if (create_threads(data))
		return (1);
	if (join_threads(data))
		return (1);
	return (0);
}
