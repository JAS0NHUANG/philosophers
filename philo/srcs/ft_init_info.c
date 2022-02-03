#include "philo.h"

int	ft_init_info(t_info **info)
{
	long	start_time;

	start_time = ft_get_time_in_ms();
	if (start_time > 0)
	{
		*info = malloc(sizeof(t_info));
		(*info)->start_time = start_time;
		(*info)->philos_array = NULL;
		pthread_mutex_init(&((*info)->printer_mutex), NULL);
		pthread_mutex_init(&((*info)->meal_eaten_adder), NULL);
	}
	else
		return (1);
	return (0);
}
