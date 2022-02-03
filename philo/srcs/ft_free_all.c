#include "philo.h"

void	ft_free_all(t_args *args, t_info *info)
{
	if (args)
		free(args);
	if (info)
	{
		pthread_mutex_destroy(&(info->printer_mutex));
		if (info->philos_array)
			free(info->philos_array);
		free(info);
	}
}
