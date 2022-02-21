/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:49:03 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/21 06:52:35 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_printer(t_philo **philo, int action)
{
	char	*is_str;

	pthread_mutex_lock(&((*philo)->data->common_lock));
	if ((*philo)->data->death > 0 || \
		(*philo)->data->fed == (*philo)->data->nbr_philo)
	{
		pthread_mutex_unlock(&((*philo)->data->common_lock));
		return ;
	}
	is_str = NULL;
	if (action == TAKE_FORK)
		is_str = "has taken a fork\n";
	if (action == EAT)
		is_str = "is eating\n";
	if (action == SLEEP)
		is_str = "is sleeping\n";
	if (action == THINK)
		is_str = "is thinking\n";
	if (action == DIE)
		is_str = "died\n";
	printf("%lu %d %s", ft_get_time_in_ms() - (*philo)->data->start_time,
		(*philo)->philo_index + 1, is_str);
	pthread_mutex_unlock(&((*philo)->data->common_lock));
}

void	ft_print_action(t_philo **philo, int action)
{
	pthread_mutex_lock(&((*philo)->data->common_lock));
	if ((*philo)->data->death > 0 || \
		(*philo)->data->fed == (*philo)->data->nbr_philo)
	{
		pthread_mutex_unlock(&((*philo)->data->common_lock));
		return ;
	}
	pthread_mutex_unlock(&((*philo)->data->common_lock));
	ft_printer(philo, action);
	return ;
}
