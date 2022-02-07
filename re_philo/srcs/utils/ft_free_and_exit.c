#include "philo.h"

void	ft_free_and_exit(t_all *all, int exit_code)
{
	if (all)
	{
		if (all->info)
		{
			pthread_mutex_destroy(&(all->info->printer_lock));
			pthread_mutex_destroy(&(all->info->life_check_lock));
			free(all->info);
		}
		if (all->philos_array)
		if (all->forks_array)
		free(all);
	}
	exit(exit_code);
}
