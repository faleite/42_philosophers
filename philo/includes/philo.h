/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:48:59 by faaraujo          #+#    #+#             */
/*   Updated: 2023/11/15 18:07:14 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> // printf
# include <stdlib.h> // malloc, free
# include <unistd.h> // write, usleep
# include <sys/time.h> // gettimeofday
# include <pthread.h> // pthread_create, pthread_join
# include <stdbool.h> // type bool
# include <limits.h> // INT_MAX

/* structures */

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
typedef struct s_data	t_data;

/* Operation code */
typedef enum e_status
{
	THINK,
	EAT,
	SLEEP,
	DEAD
}			t_status;

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
	int			first_fork;
	int			second_fork;
	int			meals_nbr;
	size_t		meals_last;
	t_status	status;
	pthread_t	thread;
	t_data		*data;
}				t_philo;

struct s_data
{
	int				nphilos;
	int				time_eat;
	int				time_sleep;
	int				ntimes_eat;
	bool			end_philo;
	size_t			time_die;
	size_t			time_philos;
	pthread_mutex_t	mutex_msg;
	pthread_mutex_t	mutex_end;
	t_fork			*forks;
	t_philo			*philo;
};

/* Utils */
int			error_case(t_data *data, char *msg);
int			check_int_max(char **argv);
void		msg_routine(t_philo *philo, char *msg);
size_t		get_curr_time(void);
long int	ft_atol(const char *str);

/* Parsing */
int			take_arg(int argc, char **argv);
int			put_arg(t_data *data, char **argv);
int			init_forks(t_data *data);
void		init_philo(t_data *data);

/* Actions */
void		philo_eat(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		*routine(void *arg);

/* Table */
int			odd_even(t_philo *philo, int first_fork, int second_fork);
int			not_usable(t_philo *philo, int fork);
int			give_me_forks(t_philo *philo);
int			philo_end(t_philo *philo);
void		start_meals(t_data *data);
void		unlock_forks(t_philo *philo, int value);
void		give_off_forks(t_philo *philo);
void		lifetime_of_philo(t_philo *philo, size_t time);

#endif /* PHILO_H */