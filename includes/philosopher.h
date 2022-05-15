/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:07:04 by samajat           #+#    #+#             */
/*   Updated: 2022/05/15 23:52:11 by samajat          ###   ########.fr       */
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


//Philospher status
#define NOTHING      0
#define EATING      25
#define SLEEPING    26
#define THINKING    27
#define DYING       28

//utils
#define TRUE        1
#define FALSE       0

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}   t_list	;


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
    int             fork_index;
    int             fork_available;
    pthread_mutex_t fork_mutex;
}   t_fork;

typedef struct s_philosopher
{
    int     identity;
    int     status;
    t_fork  right_fork;
    t_fork  left_fork;
}   t_philosopher;


//Init
void    initialize_user_input (t_data *data, char   **argv);

//Philosopher situations
int do_sleeping (t_data *data, t_philosopher *philosopher);
int do_eating ();
int do_thinking ();

//ft_time
long    get_passed_time_in_milli(long program_launch_time);
long    get_actual_time_in_milliseconds();

//utils
int	ft_atoi(const char *nptr);

#endif