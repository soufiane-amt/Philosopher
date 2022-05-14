/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:25:08 by samajat           #+#    #+#             */
/*   Updated: 2022/05/14 00:56:24 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int do_sleeping (s_input *input, t_philosopher *philosopher)
{
    printf("%d ", get_passed_time_in_milli(input->launching_time, get_actual_time_in_milliseconds()));
    printf ("%d is sleeping ", philosopher->identity);
    while ()
    {
        /* code */
    }
    
}
int do_thinking (s_input *input);
int do_eating (s_input *input);
