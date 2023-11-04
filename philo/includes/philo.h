/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:48:59 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/04 09:12:05 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <unistd.h> // write, usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h> // pthread_create, pthread_detach, pthread_join
# include <stdbool.h> // type bool
# include <limits.h> // INT_MAX
# include <string.h> // memset

/* structures */

typedef struct s_data	t_data;

/**
 * @brief FORK
*/
typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}					t_fork;

/**
 * @name PHILO
 * @brief ./philo 5 800 200 200 [5]
 * @param meals_last time passed from last meal (for check if philo is dies)
 * @param thread is a philo
*/
typedef struct s_philo
{
	int			id;
	long		meals_nbr;
	bool		meals_max;
	long		meals_last;
	pthread_t	thread;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data		*data;
}				t_philo;

/**
 * @name DATA
 * @brief ./philo 5 800 200 200 [5]
 * @param philos 5
 * @param forks 5
 * @param time_die 800
 * @param time_eat 200
 * @param time_sleep 200
 * @param ntimes_eat [5] | Use flag (if -1) dont have argument
 * @param init_philos Start simulation of the philosophers
 * @param end_philos A philo dies or all philos full
 * @param forks array of FORKS
 * @param philos array of PHILOS
*/
struct s_data
{
	int			philos;
	int			forks;
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			ntimes_eat;
	int			init_philos;
	bool		end_philos;
	t_fork		*forks;
	t_philo		*philos;
};

/* Utils */
int		take_arg(int argc, char **argv);
int		check_arg(char **argv);
int		ft_isdigit(int c);
int		ft_atoi(const char *ptr);

#endif /* PHILO_H */