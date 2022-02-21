/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:38:29 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/19 06:47:55 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_take_forks(t_philo **philo)
{
	int	first_fork;
	int	second_fork;

	if (!ft_still_alive(philo) && ft_all_fed(philo))
		return (1);
	if ((*philo)->philo_index % 2 == 0)
	{
		ft_sleep_ms(1);
		first_fork = (*philo)->philo_index;
		second_fork = ((*philo)->philo_index + 1) % (*philo)->data->nbr_philo;
	}
	else
	{
		first_fork = ((*philo)->philo_index + 1) % (*philo)->data->nbr_philo;
		second_fork = (*philo)->philo_index;
	}
	pthread_mutex_lock(&((*philo)->data->forks_array[first_fork]));
	(*philo)->has_left_fork = 1;
	ft_print_action(philo, TAKE_FORK);
	pthread_mutex_lock(&((*philo)->data->forks_array[second_fork]));
	(*philo)->has_right_fork = 1;
	ft_print_action(philo, TAKE_FORK);
	return (0);
}

int	ft_eating(t_philo **philo)
{
	if (!ft_still_alive(philo) && ft_all_fed(philo))
		return (1);
	(*philo)->last_meal_time = ft_get_time_in_ms();
	ft_print_action(philo, EAT);
	if ((*philo)->data->t_t_die <= (*philo)->data->t_t_eat)
	{
		ft_sleep_ms((*philo)->data->t_t_die);
		ft_print_action(philo, DIE);
		pthread_mutex_lock(&((*philo)->data->common_lock));
		(*philo)->data->death += 1;
		pthread_mutex_unlock(&((*philo)->data->common_lock));
		ft_putdown_forks(philo);
		return (1);
	}
	pthread_mutex_lock(&((*philo)->data->common_lock));
	(*philo)->meal_eaten += 1;
	if ((*philo)->meal_eaten == (*philo)->data->must_eat)
		(*philo)->data->fed += 1;
	pthread_mutex_unlock(&((*philo)->data->common_lock));
	ft_sleep_ms((*philo)->data->t_t_eat);
	if (!ft_still_alive(philo) && ft_all_fed(philo))
		return (1);
	return (0);
}

int	ft_putdown_forks(t_philo **philo)
{
	int	right_fork_index;
	int	left_fork_index;

	right_fork_index = (*philo)->philo_index;
	left_fork_index = ((*philo)->philo_index + 1) % (*philo)->data->nbr_philo;
	if ((*philo)->has_left_fork == 1)
	{
		(*philo)->has_left_fork = 0;
		pthread_mutex_unlock(&((*philo)->data->forks_array[left_fork_index]));
	}
	if ((*philo)->has_right_fork == 1)
	{
		(*philo)->has_right_fork = 0;
		pthread_mutex_unlock(&((*philo)->data->forks_array[right_fork_index]));
	}
	return (0);
}

int	ft_sleeping(t_philo **philo)
{
	if (!ft_still_alive(philo) && ft_all_fed(philo))
		return (1);
	if ((*philo)->data->t_t_sleep >= (*philo)->data->t_t_die || \
		(*philo)->data->t_t_sleep + (*philo)->data->t_t_eat >= (*philo)->data->t_t_die)
	{
		ft_sleep_ms((*philo)->data->t_t_die - (*philo)->data->t_t_eat);
		ft_print_action(philo, DIE);
		pthread_mutex_lock(&((*philo)->data->common_lock));
		(*philo)->data->death += 1;
		pthread_mutex_unlock(&((*philo)->data->common_lock));
		ft_putdown_forks(philo);
		return (1);
	}
	ft_print_action(philo, SLEEP);
	ft_sleep_ms((*philo)->data->t_t_sleep);
	if (!ft_still_alive(philo))
		return (1);
	return (0);
}

int	ft_thinking(t_philo **philo)
{
	if (!ft_still_alive(philo) && ft_all_fed(philo))
		return (1);
	ft_print_action(philo, THINK);
	if (ft_get_time_in_ms() + (unsigned long)(*philo)->data->t_t_eat < \
		(*philo)->last_meal_time + (unsigned long)(*philo)->data->t_t_die)
		ft_sleep_ms((*philo)->data->t_t_eat + 10);
	if ((*philo)->data->t_t_die <= (*philo)->data->t_t_eat * 2)
	{
		ft_sleep_ms((*philo)->data->t_t_die - (*philo)->data->t_t_eat - \
				(*philo)->data->t_t_sleep);
		ft_print_action(philo, DIE);
		pthread_mutex_lock(&((*philo)->data->common_lock));
		(*philo)->data->death += 1;
		pthread_mutex_unlock(&((*philo)->data->common_lock));
		ft_putdown_forks(philo);
		return (1);
	}
	return (0);
}
