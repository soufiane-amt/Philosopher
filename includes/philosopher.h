/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:07:04 by samajat           #+#    #+#             */
/*   Updated: 2022/05/21 19:23:04 by samajat          ###   ########.fr       */
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

//Structures
typedef struct s_data
{
    long    number_of_philosophers;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    launching_time;
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
    t_data          data;
}   t_philosopher;


//main funcs
void            *ft_start_dinner (void *philosopher);
//Init
void            initialize_user_input (t_data *data, char   **argv);
void            initialize_forks(t_philosopher *philosopher, int forks_number);
t_philosopher   *initialize_philosopher(int identity, int forks_number);
void            set_to_philosophers_to_default(t_list **philsophers, t_data data);
int             let_the_fun_bigins(t_list   **philosophers);

//Philosopher situations
void             do_sleeping (long  launching_time, t_philosopher *philosopher);
void             do_eating (long    launching_time, t_philosopher *philosopher);
void             do_thinking (long  launching_time, t_philosopher *philosopher);
int             wait_untill_taking_forks(long   launching_time, t_philosopher *philosopher);
int             the_philosopher_is_dead(t_philosopher *philosopher);

//ft_time
long            get_passed_time_in_milli(long program_launch_time);
long            get_actual_time_in_milliseconds();
int             ft_usleep(long  time_in_milli, t_philosopher *philosopher);

//utils
int             ft_atoi(const char *nptr);
size_t          ft_strlen(const char *str);
int             ft_strcmp(char *s1, char *s2);
int	            ft_isdigit(int c);
int             ft_all_allocated(int    number_of_variables, ...);
void            print_philo_data(t_list **philos);
void            *salut(void *);
#endif