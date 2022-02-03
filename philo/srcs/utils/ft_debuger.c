/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debuger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:05:54 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/03 14:33:34 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_debuger(t_args *args, t_data *data)
{
	if (args)
	{
		printf("args-------------------------------------------->\n");
		printf("nbr philo: %d\n", args->nbr_philo);
		printf("t t die: %d\n", args->t_t_die);
		printf("t t eat: %d\n", args->t_t_eat);
		printf("t t sleep: %d\n", args->t_t_sleep);
		printf("must eat: %d\n", args->must_eat);
		printf("------------------------------------------------>\n\n");
	}
	if (data)
	{
		printf("data-------------------------------------------->\n");
		printf("start time in ms: %ld\n", data->start_time);
		printf("printer mutex addr: %p\n", &(data->printer_lock));
		printf("------------------------------------------------>\n\n");
	}
}
