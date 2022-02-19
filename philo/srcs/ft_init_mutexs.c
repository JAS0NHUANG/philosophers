/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mutexs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:55:03 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/15 16:55:04 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutexs(t_data **data)
{
	int	index;

	index = 0;
	if (pthread_mutex_init(&((*data)->common_lock), NULL) != 0)
		return (ERR_MUTEX);
	(*data)->forks_array = malloc(sizeof(pthread_mutex_t) * (*data)->nbr_philo);
	if (!(*data)->forks_array)
		return (ERR_MALLOC);
	while (index < (*data)->nbr_philo)
	{
		if (pthread_mutex_init(&((*data)->forks_array[index]), NULL) != 0)
			return (ERR_MUTEX);
		index++;
	}
	return (0);
}
