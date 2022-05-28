/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_simulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:23:03 by samajat           #+#    #+#             */
/*   Updated: 2022/05/28 21:22:21 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	simulation_ended(long ac, long time_to_die, t_philosopher *philo)
{
	if (ac - philo->last_time_eaten > time_to_die)
	{
		pthread_mutex_lock(&philo->data->printing_mutex);
		printf("%ld %d died \n", get_passed_time_in_milli(
				philo->data->launching_time), philo->identity);
		pthread_mutex_unlock(&philo->data->threads_controller);
		return (1);
	}
	if (philo->data->number_of_philosophers
		== philo->data->philos_reached_min_eat)
	{
		pthread_mutex_lock(&philo->data->printing_mutex);
		printf("Simulation is Over\n");
		pthread_mutex_unlock(&philo->data->threads_controller);
		return (1);
	}
	return (0);
}

void	*check_simult_end(void *a)
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
		if (simulation_ended(ac, time_to_die, philo))
			break ;
		usleep(pt_wait);
		if (pt_wait == 500)
			pt_wait = 100;
		else
			pt_wait += 50;
	}
	return (NULL);
}

void	*ft_start_dinner(void *philosopher)
{
	long			launching_time;
	t_philosopher	*philo;
	pthread_t		death_checker;
	static int		i;

	philo = (t_philosopher *)philosopher;
	if (philo->identity % 2 == 0)
		usleep(philo->data->time_to_eat * 1000);
	pthread_create(&death_checker, NULL, check_simult_end, philo);
	pthread_detach(death_checker);
	launching_time = get_actual_time_in_milliseconds();
	philo->last_time_eaten = launching_time;
	while (1)
	{
		if (!(i++))
			philo->data->launching_time = launching_time;
		wait_untill_taking_forks(philosopher);
		do_eating(philosopher);
		do_sleeping(philosopher);
		do_thinking(philosopher);
	}
	return (NULL);
}

int	let_the_fun_bigins(t_list **philosophers)
{
	t_list	*temp;

	temp = *philosophers;
	while (temp)
	{
		pthread_detach(((t_philosopher *)temp->content)->thread_id);
		temp = temp->next;
	}
	return (0);
}
