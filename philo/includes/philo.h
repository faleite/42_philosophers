/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:48:59 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/12 14:27:20 by faaraujo         ###   ########.fr       */
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
# include <errno.h> // macro status errors for threads 

/* Operation code */
typedef enum e_operator
{
	THINK,
	EAT,
	SLEEP,
	DEAD
}			t_operator;

/* structures */
typedef struct s_data	t_data;

/**
 * @brief FORK
*/
typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				usable;
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
	int			status;
	int			first_fork;
	int			second_fork;
	long		meals_nbr;
	long		meals_last;
	pthread_t	thread;
	t_data		*data;
}				t_philo;

/**
 * @name DATA
 * @brief ./philo 5 800 200 200 [5]
 * @param nphilos 5
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
	int				nphilos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				ntimes_eat;
	bool			end_philo;
	bool			start_philos;
	size_t			time_philos;
	pthread_mutex_t	*mutex;
	t_fork			*forks;
	t_philo			*philos;
};

/* Utils */
int			error_case(t_data *data, char *msg);
int			check_int_max(char **argv);
long int	ft_atol(const char *str);
size_t		get_curr_time(void);

/* Parsing */
int			take_arg(int argc, char **argv);
int			put_arg(t_data *data, char **argv);
int			init_data(t_data *data);

/* Actions */
void		msg_routine(t_philo *philo, char *msg);
void		philo_eat(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		unlock_forks(t_philo *philo, int value);
void		give_off_forks(t_philo *philo);
void		lifetime_of_philo(t_philo *philo, size_t time);
int			odd_even(t_philo *philo, int first_fork, int second_fork);
int			not_usable(t_philo *philo, int fork);
int			give_me_forks(t_philo *philo);
int			philo_end(t_philo *philo);
void		*routine(void *arg);
void		start_meals(t_data *data);

#endif /* PHILO_H */