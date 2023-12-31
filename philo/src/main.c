/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:07:26 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/15 17:11:40 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (take_arg(argc, argv))
		return (error_case(&data, "Invalid arguments"));
	if (put_arg(&data, argv))
		return (error_case(&data, "Enter a valid value"));
	init_philo(&data);
	start_meals(&data);
	free(data.forks);
	free(data.philo);
	return (0);
}
