/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:20:48 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/18 11:50:37 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_data(t_data *data)
{
	int	index;

	index = 0;
	if (data)
	{
		if (data->forks_array)
		{
			while (index < data->nbr_philo)
			{
				pthread_mutex_trylock(&(data->forks_array[index]));
				pthread_mutex_unlock(&(data->forks_array[index]));
				pthread_mutex_destroy(&(data->forks_array[index]));
				index++;
			}
			free(data->forks_array);
		}
		if (data->philos_array)
			free(data->philos_array);
		free(data);
	}
}

void	ft_print_arg_error(int error_code)
{
	char	*str;

	str = NULL;
	if (error_code == ERR_ARGS_AMOUNT)
		str = "Wrong amount of arguments\n";
	if (error_code == ERR_ARGS_NAN)
		str = "Non numeric argument(s)\n";
	if (error_code == ERR_ARGS_NEG)
		str = "Negative value(s)\n";
	if (error_code == ERR_ARGS_EMPTY)
		str = "0 or NULL argument(s)\n";
	if (error_code == ERR_ARGS_NOPHILO)
		str = "No philosopher\n";
	if (error_code == ERR_ARGS_TOOLONG)
		str = "Number is too big\n";
	printf("Error: %s", str);
}

void	ft_print_error(int error_code)
{
	char	*str;

	str = NULL;
	if (error_code >= ERR_ARGS_AMOUNT && error_code <= ERR_ARGS_TOOLONG)
		ft_print_arg_error(error_code);
	else
	{
		if (error_code == ERR_GETTIME)
			str = "Get time failed\n";
		if (error_code == ERR_INIT)
			str = "Program initialization failed\n";
		if (error_code == ERR_MALLOC)
			str = "Memory allocation failed\n";
		if (error_code == ERR_MUTEX)
			str = "Mutex initialization failed\n";
		if (error_code == ERR_PTHREAD)
			str = "Thread creation failed\n";
		printf("Error: %s", str);
	}
}

int	ft_return(int ret_value, t_data *data)
{
	if (ret_value != 0)
		ft_print_error(ret_value);
	ft_free_data(data);
	return (ret_value);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		ret_value;

	data = NULL;
	ret_value = 0;
	ret_value = ft_get_data(ac, av, &data);
	if (ret_value != 0)
		return (ft_return(ret_value, data));
	ret_value = ft_init_mutexs(&data);
	if (ret_value != 0)
		return (ft_return(ret_value, data));
	ret_value = ft_run_philo(&data);
	return (ft_return(ret_value, data));
}
