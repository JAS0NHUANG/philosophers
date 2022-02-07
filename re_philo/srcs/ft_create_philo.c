
void	*ft_philos_life(void *philo)
{
	t_philo		*philo_holder;

	philo_holder = (t_philo *)philo;
	printf("philo meal_eaten: %d\n", philo_holder->meal_eaten);
	printf("philo philo_id: %d\n", philo_holder->philo_id);
	printf("hello philo\n");
	return (NULL);
}

void	ft_init_philos(int nbr_philo, t_all **all)
{
	int	index;
	t_philo	*philos_array;

	philos_array = malloc(sizeof(t_philo) * nbr_philo);
	index = 0;
	while (index < nbr_philo)
	{
		philos_array[index] = malloc(sizeof(t_philo));
		philos_array[index]->meal_eaten = 0;
		philos_array[index]->philo_id = index;
		pthread_create(&(philos_array[index]->philo_thread), NULL,
			&ft_philos_life, (void *)(*all));
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
