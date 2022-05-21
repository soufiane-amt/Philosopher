/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:25:08 by samajat           #+#    #+#             */
/*   Updated: 2022/05/21 19:00:35 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void do_sleeping (long  launching_time, t_philosopher *philosopher)
{
    if (philosopher->status == DEAD)
        return ;
    philosopher->left_fork->available = TRUE;
    philosopher->right_fork->available = TRUE;
    pthread_mutex_unlock(philosopher->left_fork->mutex);
    pthread_mutex_unlock(philosopher->right_fork->mutex);
    printf("%ld ", get_passed_time_in_milli(launching_time));
    printf ("%d is sleeping \n", philosopher->identity);
    ft_usleep(philosopher->data.time_to_sleep * 1000, philosopher);
}


void do_eating (long  launching_time, t_philosopher *philosopher)
{
    if (philosopher->status == DEAD)
        return ;
    printf ("%ld ", get_passed_time_in_milli(launching_time));
    printf ("%d is eating \n", philosopher->identity);
    philosopher->last_time_eaten = get_actual_time_in_milliseconds();
    ft_usleep(philosopher->data.time_to_eat * 1000, philosopher);
}

void do_thinking (long  launching_time, t_philosopher *philosopher)
{
    if (philosopher->status == DEAD)
        return ;
    philosopher->last_time_eaten = get_actual_time_in_milliseconds();
    printf("%ld ", get_passed_time_in_milli(launching_time));
    printf ("%d is thinking \n", philosopher->identity);
}

int the_philosopher_is_dead(t_philosopher *philosopher)
{
    if (get_actual_time_in_milliseconds() - philosopher->last_time_eaten <= philosopher->last_time_eaten)
    {
        printf("%ld ", get_passed_time_in_milli(philosopher->last_time_eaten));
        printf ("%d died \n", philosopher->identity);
        return (1);
    }
    return (0);
}

int wait_untill_taking_forks(long  launching_time, t_philosopher *philosopher)
{
    if (philosopher->status == DEAD)
        return (0);
    if(philosopher->left_fork->available)
    {
        pthread_mutex_lock(philosopher->left_fork->mutex);
        philosopher->left_fork->available = FALSE;
        printf("%ld ", get_passed_time_in_milli(launching_time));
        printf ("%d is taking a fork \n", philosopher->identity);
    }
    if(philosopher->right_fork->available)
    {
        pthread_mutex_lock(philosopher->right_fork->mutex);
        philosopher->right_fork->available = FALSE;
        printf("%ld ", get_passed_time_in_milli(launching_time));
        printf ("%d is taking a fork \n", philosopher->identity);
    }
    if (!philosopher->left_fork->available || !philosopher->right_fork->available)
        wait_untill_taking_forks(launching_time, philosopher);
    return(1);
}
