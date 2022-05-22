/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:25:08 by samajat           #+#    #+#             */
/*   Updated: 2022/05/22 20:48:54 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void do_sleeping (long  launching_time, t_philosopher *philosopher)
{
    if (philosopher->status == DEAD)
    {
        printf("%ld %d died \n", get_passed_time_in_milli(philosopher->last_time_eaten), philosopher->identity);
        return ;
    }
    philosopher->left_fork->available = TRUE;
    philosopher->right_fork->available = TRUE;
    pthread_mutex_unlock(philosopher->left_fork->mutex);
    pthread_mutex_unlock(philosopher->right_fork->mutex);
    printf("%ld %d is sleeping \n", get_passed_time_in_milli(launching_time), philosopher->identity);
    // ft_usleep(philosopher->data->time_to_sleep, philosopher);
    usleep(philosopher->data->time_to_sleep * 1000);
}


void do_eating (long  launching_time, t_philosopher *philosopher)
{
    printf ("%ld %d is eating \n", get_passed_time_in_milli(launching_time), philosopher->identity);
    philosopher->last_time_eaten = get_actual_time_in_milliseconds();
    // ft_usleep(philosopher->data->time_to_eat, philosopher);
    usleep(philosopher->data->time_to_eat * 1000);
}

void do_thinking (long  launching_time, t_philosopher *philosopher)
{
    if (philosopher->status == DEAD)
    {
        return ;
    }
    philosopher->last_time_eaten = get_actual_time_in_milliseconds();
    printf("%ld %d is thinking \n", get_passed_time_in_milli(launching_time), philosopher->identity);
}

int the_philosopher_is_dead(t_philosopher *philosopher)
{
    if (get_actual_time_in_milliseconds() - philosopher->last_time_eaten >= philosopher->data->time_to_die)
    {   
        philosopher->data->dead_philosopher.identity = philosopher->identity;
        // printf("%ld %d died \n", get_passed_time_in_milli(philosopher->last_time_eaten), philosopher->identity);
        philosopher->status= DEAD;
        return (1);
    }
    return (0);
}

// int wait_untill_taking_forks(long  launching_time, t_philosopher *philosopher)
// {
//     // printf("%d : philosopher ->status : %d\n", philosopher->identity, philosopheer->status);
//     if (philosopher->status == DEAD)
//         return (0);
//     if(philosopher->right_fork->available && philosopher->identity != 2)
//     {
//         pthread_mutex_lock(philosopher->right_fork->mutex);
//         philosopher->right_fork->available = FALSE;
//         printf("%ld %d is taking a fork right\n", get_passed_time_in_milli(launching_time), philosopher->identity);
//     }
//     if (philosopher->left_fork->available && philosopher->identity != 2)
//     {
//         pthread_mutex_lock(philosopher->left_fork->mutex);
//         philosopher->left_fork->available = FALSE;
//         printf("%ld %d is taking a fork left\n", get_passed_time_in_milli(launching_time), philosopher->identity);
//     }
//     if (!philosopher->left_fork->available && !philosopher->right_fork->available )
//         wait_untill_taking_forks(launching_time, philosopher);
//     return(1);
// }


int wait_untill_taking_forks(long  launching_time, t_philosopher *philosopher)
{
    pthread_mutex_lock(philosopher->left_fork->mutex);
    philosopher->left_fork->available = FALSE;
    printf("%ld %d is taking a fork left\n", get_passed_time_in_milli(launching_time), philosopher->identity);
    pthread_mutex_lock(philosopher->right_fork->mutex);
    philosopher->right_fork->available = FALSE;
    printf("%ld %d is taking a fork right\n", get_passed_time_in_milli(launching_time), philosopher->identity);
    return(1);
}

