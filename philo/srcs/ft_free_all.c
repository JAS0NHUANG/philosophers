#include "philo.h"

void	ft_free_all(t_args *args, t_data *data)
{
	if (args)
		free(args);
	if (data)
	{
		pthread_mutex_destroy(&(data->printer_lock));
		if (data->philos_array)
			free(data->philos_array);
		free(data);
	}
}
