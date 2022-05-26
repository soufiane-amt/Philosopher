/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:05 by samajat           #+#    #+#             */
/*   Updated: 2022/05/25 22:27:13 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    initialize_user_input (t_data *data, char   **argv)
{
    //handle bad args
    // data->launching_time = get_actual_time_in_milliseconds ();
    data->number_of_philosophers = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->nbr_times_a_philo_must_eat = ft_atoi(argv[5]);
    data->dead_philosopher.identity = 0;
    data->dead_philosopher.time = 0;
    data->some_one_is_dead = 0;
    pthread_mutex_init(&(data->printing_mutex), NULL);
    pthread_mutex_init(&(data->hhhhh), NULL);
	data->philos_reached_min_eat = 0;
}

void    initialize_forks(t_philosopher *philosopher, int forks_number)
{
    static t_fork                  *left_for_next;
    static t_philosopher           *first_philosopher;

    if (philosopher->identity == 1)
    {
        philosopher->right_fork->available = TRUE;
        philosopher->right_fork->index = philosopher->identity - 1;
        first_philosopher = philosopher;
    }
    else
    {
        philosopher->right_fork->index = philosopher->identity - 1;
        philosopher->left_fork = left_for_next;
    }
    philosopher->right_fork->available = TRUE;
    pthread_mutex_init (philosopher->right_fork->mutex, NULL);
    left_for_next = philosopher->right_fork;
    if (forks_number == philosopher->identity)
        first_philosopher->left_fork = philosopher->right_fork;
}


t_philosopher    *initialize_philosopher(int identity, int forks_number)
{
    t_philosopher   *philsopher;

    philsopher = malloc (sizeof(t_philosopher));
    philsopher->left_fork = malloc (sizeof(t_fork));
    philsopher->right_fork = malloc (sizeof(t_fork));
    philsopher->left_fork->mutex = malloc (sizeof(pthread_mutex_t));
    philsopher->right_fork->mutex = malloc (sizeof(pthread_mutex_t));
    if (!ft_all_allocated(5, philsopher, philsopher->left_fork,
            philsopher->right_fork, philsopher->left_fork->mutex,
            philsopher->right_fork->mutex))
        return (NULL);
    philsopher->identity = identity;
    philsopher->status = ALIVE;
    initialize_forks(philsopher, forks_number);
	philsopher->nbr_meals = 0;
    return (philsopher);
}

void    set_to_philosophers_to_default(t_list **philsophers, t_data *data)
{
    int             identity;
    t_philosopher   *new_philosopher;

    identity = 1;
    while (identity <= data->number_of_philosophers)
    {
        new_philosopher = initialize_philosopher(identity, data->number_of_philosophers);
        new_philosopher->data = data;
        pthread_create(&new_philosopher->thread_id, NULL, ft_start_dinner, (void *)new_philosopher);
        ft_lstadd_back(philsophers, ft_lstnew((void *)new_philosopher));
        identity++;
    }
}

//The purpose of this file is to initialize philosophers and forks to default values