/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:07:04 by samajat           #+#    #+#             */
/*   Updated: 2022/05/19 22:53:15 by samajat          ###   ########.fr       */
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
    int     identity;
    int     status;
    t_fork  *right_fork;
    t_fork  *left_fork;
}   t_philosopher;


//Init
void            initialize_user_input (t_data *data, char   **argv);
void            initialize_forks(t_philosopher *philosopher, int forks_number);
t_philosopher   *initialize_philosopher(int identity, int forks_number);
void            build_philosophers(t_list **philsophers, t_data data);

//Philosopher situations
void             do_sleeping (t_data *data, t_philosopher *philosopher);
void             do_eating (t_data *data, t_philosopher *philosopher);
void             do_thinking (t_data *data, t_philosopher *philosopher);
int             wait_untill_taking_forks(t_data *data, t_philosopher *philosopher);

//ft_time
long            get_passed_time_in_milli(long program_launch_time);
long            get_actual_time_in_milliseconds();

//utils
int             ft_atoi(const char *nptr);
size_t          ft_strlen(const char *str);
int             ft_strcmp(char *s1, char *s2);
int	            ft_isdigit(int c);
int             ft_all_allocated(int    number_of_variables, ...);
#endif