/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:01:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/09 21:42:43 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	catch_forks(t_philo *philo)
{
	if (philo->id % 2)
		odd_philo(philo);
	else
		even_philo(philo);
}
