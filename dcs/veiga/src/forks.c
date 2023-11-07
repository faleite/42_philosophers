/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:36:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/19 16:21:22 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	pick_up_left(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->left_fork].mutex_fork);
	if (!philo->data->fork[philo->left_fork].aval)
	{
		pthread_mutex_unlock(&philo->data->fork[philo->left_fork].mutex_fork);
		if (philo->state != THINK)
			print_msg(philo, "is thinking");
		philo->state = THINK;
		return (1);
	}
	pthread_mutex_lock(&philo->data->fork[philo->right_fork].mutex_fork);
	if (!philo->data->fork[philo->right_fork].aval)
	{
		pthread_mutex_unlock(&philo->data->fork[philo->left_fork].mutex_fork);
		pthread_mutex_unlock(&philo->data->fork[philo->right_fork].mutex_fork);
		if (philo->state != THINK)
			print_msg(philo, "is thinking");
		philo->state = THINK;
		return (1);
	}
	print_msg(philo, "has taken a fork");
	print_msg(philo, "has taken a fork");
	return (0);
}

int	pick_up_right(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork[philo->right_fork].mutex_fork);
	if (!philo->data->fork[philo->right_fork].aval)
	{
		pthread_mutex_unlock(&philo->data->fork[philo->right_fork].mutex_fork);
		if (philo->state != THINK)
			print_msg(philo, "is thinking");
		philo->state = THINK;
		return (1);
	}
	pthread_mutex_lock(&philo->data->fork[philo->left_fork].mutex_fork);
	if (!philo->data->fork[philo->left_fork].aval)
	{
		pthread_mutex_unlock(&philo->data->fork[philo->right_fork].mutex_fork);
		pthread_mutex_unlock(&philo->data->fork[philo->left_fork].mutex_fork);
		if (philo->state != THINK)
			print_msg(philo, "is thinking");
		philo->state = THINK;
		return (1);
	}
	print_msg(philo, "has taken a fork");
	print_msg(philo, "has taken a fork");
	return (0);
}

int	pick_up_fork(t_philo *philo)
{
	if (philo->id % 2)
	{
		if (pick_up_left(philo) == 1)
			return (1);
	}
	else
	{
		if (pick_up_right(philo) == 1)
			return (1);
	}
	philo->data->fork[philo->left_fork].aval = 0;
	philo->data->fork[philo->right_fork].aval = 0;
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork].mutex_fork);
	pthread_mutex_unlock(&philo->data->fork[philo->right_fork].mutex_fork);
	return (0);
}

void	drop_forks(t_philo *philo)
{
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->data->fork[philo->left_fork].mutex_fork);
		pthread_mutex_lock(&philo->data->fork[philo->right_fork].mutex_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->data->fork[philo->right_fork].mutex_fork);
		pthread_mutex_lock(&philo->data->fork[philo->left_fork].mutex_fork);
	}
	philo->data->fork[philo->left_fork].aval = 1;
	philo->data->fork[philo->right_fork].aval = 1;
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork].mutex_fork);
	pthread_mutex_unlock(&philo->data->fork[philo->right_fork].mutex_fork);
}
