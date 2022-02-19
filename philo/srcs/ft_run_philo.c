/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:23:26 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/19 06:50:50 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	funciont to execute usleep() for x ms
*/

void	ft_sleep_ms(unsigned long ms)
{
	unsigned long	start_time;

	start_time = ft_get_time_in_ms();
	while (ft_get_time_in_ms() - start_time < ms)
		usleep(400);
}

/*
**	two functions to check if all philos are fed or anybody dead
*/

int	ft_all_fed(t_philo **philo)
{
	int	index;

	index = 0;
	pthread_mutex_lock(&((*philo)->data->common_lock));
	if ((*philo)->data->must_eat == 0)
	{
		pthread_mutex_unlock(&((*philo)->data->common_lock));
		return (0);
	}
	pthread_mutex_unlock(&((*philo)->data->common_lock));
	pthread_mutex_lock(&((*philo)->data->common_lock));
	while (index < (*philo)->data->nbr_philo)
	{
		if ((*philo)->data->philos_array[index].meal_eaten < \
			(*philo)->data->must_eat)
		{
			pthread_mutex_unlock(&((*philo)->data->common_lock));
			return (0);
		}
		index++;
	}
	pthread_mutex_unlock(&((*philo)->data->common_lock));
	return (1);
}

int	ft_still_alive(t_philo **philo)
{
	unsigned long	current_time;

	pthread_mutex_lock(&((*philo)->data->common_lock));
	current_time = ft_get_time_in_ms();
	if ((current_time - (*philo)->last_meal_time) >= \
			(unsigned long)(*philo)->data->t_t_die)
	{
		pthread_mutex_unlock(&((*philo)->data->common_lock));
		ft_print_action(philo, DIE);
		pthread_mutex_lock(&((*philo)->data->common_lock));
		(*philo)->data->death += 1;
		pthread_mutex_unlock(&((*philo)->data->common_lock));
		return (0);
	}
	if ((*philo)->data->death >= 1)
	{
		pthread_mutex_unlock(&((*philo)->data->common_lock));
		return (0);
	}
	pthread_mutex_unlock(&((*philo)->data->common_lock));
	return (1);
}

/*
**	The routine to be called inside each philo thread
*/

static void	*ft_philo_routine(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	if (philo->data->nbr_philo == 1)
	{
		ft_print_action(&philo, TAKE_FORK);
		ft_sleep_ms(philo->data->t_t_die);
		ft_print_action(&philo, DIE);
		philo->data->death += 1;
		return (NULL);
	}
	while (ft_still_alive(&philo) && !ft_all_fed(&philo))
	{
		if (ft_take_forks(&philo))
			return (NULL);
		if (ft_eating(&philo))
			return (NULL);
		if (ft_putdown_forks(&philo))
			return (NULL);
		if (ft_sleeping(&philo))
			return (NULL);
		if (ft_thinking(&philo))
			return (NULL);
	}
	return (NULL);
}

/*
**	create all the threads/philos(the thread/philo will start running the
**	routine, ft_philo_routine, immidiatly after their creation).
*/

int	ft_run_philo(t_data **data)
{
	int		index;

	(*data)->philos_array = malloc(sizeof(t_philo) * (*data)->nbr_philo);
	if (!((*data)->philos_array))
		return (ERR_MALLOC);
	index = -1;
	while (++index < (*data)->nbr_philo)
	{
		(*data)->philos_array[index].philo_index = index;
		(*data)->philos_array[index].last_meal_time = (*data)->start_time;
		(*data)->philos_array[index].meal_eaten = 0;
		(*data)->philos_array[index].has_left_fork = 0;
		(*data)->philos_array[index].has_right_fork = 0;
		(*data)->philos_array[index].data = *data;
		if (pthread_create(&((*data)->philos_array[index].philo_thread), NULL,
				ft_philo_routine, (void *)(&(*data)->philos_array[index])) != 0)
			return (ERR_PTHREAD);
	}
	index = -1;
	while (++index < (*data)->nbr_philo)
	{
		if (pthread_join((*data)->philos_array[index].philo_thread, NULL) != 0)
			return (ERR_PTHREAD);
	}
	return (0);
}
