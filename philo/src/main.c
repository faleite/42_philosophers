/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:07:26 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/12 15:22:45 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_philo	*philo;

	philo = NULL;
	if (take_arg(argc, argv))
		return (error_case(&data, "Invalid arguments"));
	if (put_arg(&data, argv))
		return (error_case(&data, "Enter a valid value"));
	if (init_data(&data))
		return (error_case(&data, "Init data not done"));
	start_meals(&data, philo);
	free(data.forks);
	free(data.philos);
	return (0);
}
