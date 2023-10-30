/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:48:59 by faaraujo          #+#    #+#             */
/*   Updated: 2023/10/30 21:08:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h> // memset
# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <unistd.h> // write, usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h> // pthread_create, pthread_detach, pthread_join

/* create struct philo */
;

typedef struct s_data
{
	int			philos;
	int			forks;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			ntimes_eat;
}	t_data;

typedef struct s_philo
{
	pthread_t	thread;
	t_data		*data;
}	t_philo;

/* Utils */
int		take_arg(int argc, char **argv);
int		check_arg(char **argv);
int		ft_isdigit(int c);
int		ft_atoi(const char *ptr);

#endif /* PHILO_H */