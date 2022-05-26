/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:07:04 by samajat           #+#    #+#             */
/*   Updated: 2022/05/25 21:28:36 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include "t_list.h"
#include <stdarg.h>
#include <limits.h>

//Philospher status
#define NOTHING      0
#define EATING      25
#define SLEEPING    26
#define THINKING    27
#define DYING       28

//utils
#define TRUE        1
#define FALSE       0

//status
#define ALIVE       1
#define DEAD        0

//ERRORS
#define	ARGC_ERROR22 "Error: Wrong amount of arguments.";
#define	ARGV_ERROR33 "Error: At least one wrong argument";

//Structures
typedef struct s_the_dead
{
    int     identity;
    long    time;
}   t_the_dead;

typedef struct s_data
{
    int	        		number_of_philosophers;
    int	        		time_to_die;
    int	        		time_to_eat;
    int	        		time_to_sleep;
    int	        		launching_time;
    int	        		nbr_times_a_philo_must_eat;
    t_the_dead  		dead_philosopher;
    int         		some_one_is_dead;
    pthread_mutex_t   	printing_mutex;
    pthread_mutex_t     hhhhh;
	int					philos_reached_min_eat;
}   t_data;

typedef struct s_fork
{
    int             index;
    int             available;
    pthread_mutex_t *mutex;
}   t_fork;

typedef struct s_philosopher
{
    int             identity;
    pthread_t       thread_id;
    int             status;
    long            last_time_eaten;
    t_fork          *right_fork;
    t_fork          *left_fork;
    t_data          *data;
	int				nbr_meals;
}   t_philosopher;


//main funcs
void            *ft_start_dinner (void *philosopher);
//Init
void            initialize_user_input (t_data *data, char   **argv);
void            initialize_forks(t_philosopher *philosopher, int forks_number);
t_philosopher   *initialize_philosopher(int identity, int forks_number);
void            set_to_philosophers_to_default(t_list **philsophers, t_data *data);
int             let_the_fun_bigins(t_list   **philosophers);

//Philosopher situations
void             do_sleeping (long  launching_time, t_philosopher *philosopher);
void             do_eating (long    launching_time, t_philosopher *philosopher);
void             do_thinking (long  launching_time, t_philosopher *philosopher);
int             wait_untill_taking_forks(long   launching_time, t_philosopher *philosopher);
int             the_philosopher_is_dead(t_philosopher *philosopher);

//ft_time
long            get_passed_time_in_milli(long program_launch_time);
long            get_actual_time_in_milliseconds(void);
int             ft_usleep(long  time_in_milli, t_philosopher *philosopher);

//Errors
int				user_input_is_valid (char	**argv, int argc);

//utils
int             ft_atoi(const char *nptr);
size_t          ft_strlen(const char *str);
int             ft_strcmp(char *s1, char *s2);
int	            ft_isdigit(int c);
int             ft_all_allocated(int    number_of_variables, ...);
void            print_philo_data(t_list **philos);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
#endif