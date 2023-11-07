/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:35:30 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/10/19 16:20:55 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

enum					e_philostate
{
	THINK,
	WAIT,
	EAT,
	SLEEP,
	DEAD
};

typedef struct s_fork
{
	pthread_mutex_t		mutex_fork;
	int					aval;
}						t_fork;

typedef struct s_data
{
	int					number_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_meals;
	int					dead;
	size_t				start_time;
	pthread_mutex_t		mutex_meal;
	pthread_mutex_t		mutex_msg;
	pthread_mutex_t		mutex_dead;
	t_fork				*fork;
}						t_data;

struct					s_philo
{
	pthread_t			thread;
	t_data				*data;
	size_t				time_of_life;
	int					id;
	int					n_eaten;
	int					left_fork;
	int					right_fork;
	enum e_philostate	state;
	size_t				last_eat;
};

/****************philosophers***********************/

int						main(int ac, char **av);
void					print_msg(t_philo *philo, char *str);

/*******************check***************************/

int						check_args(int ac, char **av);
int						check_ac(int ac);
int						check_av(int ac, char **av);

/*******************forks***************************/

int						pick_up_left(t_philo *philo);
int						pick_up_right(t_philo *philo);
int						pick_up_fork(t_philo *philo);
void					drop_forks(t_philo *philo);

/******************philo_action**********************/

void					philo_eat(t_philo *philo);
void					philo_sleep(t_philo *philo);
void					philo_think(t_philo *philo);
int						philo_is_dead(t_philo *philo);
void					action_philo(t_philo *philo, size_t time);

/*******************philo***************************/

void					init_data(int ac, char **av, t_data *data);
void					alloc_philos(t_data *data, t_philo *philo);
int						init_mutex(t_data *data);
int						one_philo(t_philo *philo);

/*******************thread***************************/

void					start(t_data *data, t_philo *philo);
void					*routine_philo(void *arg);
void					destroy_mutex(t_data *data);

/*******************time******************************/

size_t					get_timestamp(void);

/*******************utils***************************/

int						ft_atoi(const char *nptr);
int						is_digit(int ac, char **av);

#endif