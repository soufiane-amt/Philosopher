/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:23:03 by samajat           #+#    #+#             */
/*   Updated: 2022/05/27 18:19:14 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*check_death(void *a)
{
	t_philosopher	*philo;
	long			time_to_die;
	long			ac;
	long			pt_wait;

	philo = (t_philosopher *) a;
	time_to_die = philo->data->time_to_die;
	pt_wait = 100; 
	while (1)
	{
		ac = get_actual_time_in_milliseconds();
		if (ac - philo->last_time_eaten > time_to_die)
		{
			pthread_mutex_lock(&philo->data->printing_mutex);
			printf("%ld %d died \n", get_passed_time_in_milli(philo->last_time_eaten), philo->identity);
            pthread_mutex_unlock(&philo->data->threads_controller);
            break;
		}
		if (philo->data->number_of_philosophers == philo->data->philos_reached_min_eat)
		{
			pthread_mutex_lock(&philo->data->printing_mutex);
			printf("Simulation is Over\n");
            pthread_mutex_unlock(&philo->data->threads_controller);
			break;
		}
        usleep(pt_wait);
		if (pt_wait == 500)
			pt_wait = 100;
		else
			pt_wait += 50;
	}
	return (NULL);
}

void    *ft_start_dinner (void *philosopher)
{
	long launching_time;
	t_philosopher *tr;
	pthread_t death_angel;
	
	tr = (t_philosopher *)philosopher;  
	launching_time = get_actual_time_in_milliseconds();
	if (tr->identity % 2 == 0)
		usleep(tr->data->time_to_eat * 1000);
	tr->last_time_eaten = launching_time;
	pthread_create(&death_angel, NULL, check_death, tr);
	pthread_detach(death_angel);
	while(1)
	{
		wait_untill_taking_forks(launching_time, philosopher);
		do_eating(launching_time, philosopher);
		do_sleeping(launching_time, philosopher);
		do_thinking(launching_time, philosopher);
	}
	return (NULL);
}

int     let_the_fun_bigins(t_list   **philosophers)
{
	t_list  *temp;

	temp = *philosophers;
	while (temp)
	{
		pthread_detach(((t_philosopher *)temp->content)->thread_id);
		temp = temp->next;
	}
	return (0);
}