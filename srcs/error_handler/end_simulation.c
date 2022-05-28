/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 18:24:48 by samajat           #+#    #+#             */
/*   Updated: 2022/05/28 20:38:57 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_forks(t_fork	*right_fork)
{
	pthread_mutex_destroy(right_fork->mutex);
	free(right_fork);
}

void	free_data(t_data *data)
{
	pthread_mutex_destroy(&data->printing_mutex);
	pthread_mutex_destroy(&data->threads_controller);
}

void	end_simulation(t_data	*data, t_list	**philosopher)
{
	(void)philosopher;
	ft_lstclear(philosopher, &delete_philo);
	free(philosopher);
	(void)data;
	free_data(data);
}
