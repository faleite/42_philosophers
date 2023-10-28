/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:07:26 by faaraujo          #+#    #+#             */
/*   Updated: 2023/10/28 21:50:25 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	*data(void)
{
	static t_data	d;

	return (&d);
}

void	put_arg(char **argv)
{
	if (argv[1] && data()->philos == 0)
		data()->philos = ft_atoi(argv[1]);
	if (argv[1] && data()->forks == 0)
		data()->forks = ft_atoi(argv[1]);
	if (argv[2] && data()->time_die == 0)
		data()->time_die = ft_atoi(argv[2]);
	if (argv[3] && data()->time_eat == 0)
		data()->time_eat = ft_atoi(argv[3]);
	if (argv[4] && data()->time_sleep == 0)
		data()->time_sleep = ft_atoi(argv[4]);
	if (argv[5] && data()->ntimes_eat == 0)
		data()->time_sleep = ft_atoi(argv[5]);
}

void	*routine(void *arg)
{
	(void)arg;
	printf("Hello from threads\n");

	return (NULL);
}

int	create_threads(void)
{
	int	i;

	i = -1;
	while (++i < data()->philos)
	{
		if (pthread_create(data()->thread[i], NULL, &routine, NULL))
			return (1);
	}
	return (0);
}

int	join_threads(void)
{
	int	i;

	i = -1;
	while (++i < data()->philos)
	{
		if (pthread_join(data()->thread[i], NULL))
			return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (take_arg(argc, argv))
		return (1);
	put_arg(argv);
	if (create_threads())
		return (1);
	if (join_threads())
		return (1);
	return (0);
}
