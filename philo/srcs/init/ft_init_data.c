#include "philo.h"

int	ft_init_data(t_data **data)
{
	long	start_time;

	start_time = ft_get_time_in_ms();
	if (start_time > 0)
	{
		*data = malloc(sizeof(t_data));
		(*data)->start_time = start_time;
		(*data)->philos_array = NULL;
		pthread_mutex_init(&((*data)->printer_lock), NULL);
		pthread_mutex_init(&((*data)->meal_eaten_lock), NULL);
	}
	else
		return (1);
	return (0);
}
