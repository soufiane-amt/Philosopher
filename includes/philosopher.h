/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:07:04 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 00:53:18 by samajat          ###   ########.fr       */
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
#define eating      25
#define sleeping    26
#define thinking    27
#define dying       28

//utils
#define TRUE        1
#define FALSE       0

//Structures
typedef struct s_input
{
    long    number_of_philosophers;
    long    time_to_die;
    long    time_to_eat;
    long    time_to_sleep;
    long    launching_time;
}   t_input;

typedef struct s_fork
{
    int             fork_index;
    int             fork_available;
    pthread_mutex_t fork_mutex;
}   t_fork;

typedef struct s_philosopher
{
    int identity;
    int status;
    int right_fork_available;
    int left_fork_available;
}   t_philosopher;

//Philosopher situations
int do_sleeping ();
int do_eating ();
int do_thinking ();

//utils
int	ft_atoi(const char *nptr);

#endif