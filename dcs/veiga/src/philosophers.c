/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:37 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/19 15:44:22 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_msg(t_philo *philo, char *str)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->mutex_msg);
	time = get_timestamp() - philo->data->start_time;
	printf("%ld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->mutex_msg);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philo;

	if (check_args(ac, av) == 1)
		return (1);
	init_data(ac, av, &data);
	philo = malloc(sizeof(t_philo) * (data.number_of_philos));
	if (!philo)
	{
		printf("Malloc Error\n");
		return (1);
	}
	alloc_philos(&data, philo);
	start(&data, philo);
	free(data.fork);
	free(philo);
	return (0);
}
