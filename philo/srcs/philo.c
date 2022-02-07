#include "philo.h"

void	*ft_philos_routine(void *philo)
{

	if (philo)
		printf("hello philo\n");
	return (NULL);
}

void	ft_init_philos(int nbr_philo, t_philo **philos_array)
{
	int	index;
	printf("nbr philo:%d\n", nbr_philo);
	*philos_array = malloc(sizeof(t_philo) * nbr_philo);

	index = 0;
	while (index < nbr_philo)
	{
		philos_array[index] = malloc(sizeof(t_philo));
		pthread_create(&(philos_array[index]->philo_thread), NULL, &ft_philos_routine, (void *)&(philos_array[index]));
		printf("index: %d, nbr philo: %d\n", index, nbr_philo);
		index++;
	}
	index = 0;
	while (index < nbr_philo)
	{
		pthread_join(philos_array[index]->philo_thread, NULL);
		printf("index: %d, nbr philo: %d\n", index, nbr_philo);
		index++;
	}
}

int	main(int ac, char **av)
{
	int	ret_value;
	t_args	*args;
	t_data	*data;
	t_philo	*philos_array;


	ret_value = 0;
	args = NULL;
	data = NULL;
	philos_array = NULL;
	ret_value = ft_get_args(ac, av, &args);
	if (ret_value != 0)
		ft_print_error(ret_value);
	else
	{
		ft_init_data(&data);
		ft_init_philos(args->nbr_philo, &philos_array);
	}
	ft_free_all(args, data);
	return (ret_value);
}
