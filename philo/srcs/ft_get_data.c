/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:48:04 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/18 11:49:18 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_data(t_data	**data)
{
	*data = malloc(sizeof(t_data));
	if (!(*data))
		return (ERR_MALLOC);
	(*data)->nbr_philo = 0;
	(*data)->t_t_die = 0;
	(*data)->t_t_eat = 0;
	(*data)->t_t_sleep = 0;
	(*data)->must_eat = 0;
	(*data)->fed = 0;
	(*data)->death = 0;
	(*data)->start_time = 0;
	(*data)->forks_array = NULL;
	return (0);
}

static int	ft_isnum(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}

static int	ft_check_args(int ac, char **av)
{
	int	index;

	index = 1;
	if (ac < 5 || ac > 6)
		return (ERR_ARGS_AMOUNT);
	while (index < ac)
	{
		if (av[index][0] == '-')
			return (ERR_ARGS_NEG);
		if (!ft_isnum(av[index]))
			return (ERR_ARGS_NAN);
		if (ft_strlen(av[index]) == 0 || ft_atoi(av[index]) == 0)
			return (ERR_ARGS_EMPTY);
		if (index == 1 && ft_atoi(av[index]) == 0)
			return (ERR_ARGS_NOPHILO);
		if (ft_strlen(av[1]) > 5 || ft_atoi(av[1]) > 9999)
			return (ERR_ARGS_TOOLONG);
		if (ft_atoi(av[index]) <= 0)
			return (ERR_ARGS_TOOLONG);
		index++;
	}
	return (0);
}

int	ft_get_data(int ac, char **av, t_data **data)
{
	int		ret_value;

	ret_value = 0;
	ret_value = ft_check_args(ac, av);
	if (ret_value != 0)
		return (ret_value);
	ret_value = ft_init_data(data);
	if (ret_value != 0)
		return (ret_value);
	(*data)->nbr_philo = ft_atoi(av[1]);
	(*data)->t_t_die = ft_atoi(av[2]);
	(*data)->t_t_eat = ft_atoi(av[3]);
	(*data)->t_t_sleep = ft_atoi(av[4]);
	if (av[5])
		(*data)->must_eat = ft_atoi(av[5]);
	(*data)->fed = 0;
	(*data)->start_time = ft_get_time_in_ms();
	if ((*data)->start_time == 0)
		ret_value = ERR_GETTIME;
	return (ret_value);
}
