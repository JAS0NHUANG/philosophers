#include "philo.h"

void	ft_debuger(t_args *args, t_info *info)
{
	if (args)
	{
		printf("args-------------------------------------------->\n");
		printf("nbr philo: %d\n", args->nbr_philo);
		printf("t t die: %d\n", args->t_t_die);
		printf("t t eat: %d\n", args->t_t_eat);
		printf("t t sleep: %d\n", args->t_t_sleep);
		printf("must eat: %d\n", args->must_eat);
		printf("------------------------------------------------>\n\n");
	}
	if (info)
	{
		printf("info-------------------------------------------->\n");
		printf("start time in ms: %ld\n", info->start_time);
		printf("printer mutex addr: %p\n", &(info->printer_mutex));
		printf("------------------------------------------------>\n\n");
	}
}

void	ft_init_philos(t_args *args, t_philo ***philos_array)
{
	*philos_array = malloc(sizeof(t_philo *) * args->nbr_philo);
}

int	main(int ac, char **av)
{
	int	ret_value;
	t_args	*args;
	t_info	*info;
	t_philo	**philos_array;


	ret_value = 0;
	args = NULL;
	info = NULL;
	ret_value = ft_get_args(ac, av, &args);
	if (ret_value != 0)
		ft_print_error(ret_value);
	else
	{
		ft_init_info(&info);
		ft_init_philos(args, &philos_array);
		info->philos_array = philos_array;
	}
	pthread_mutex_lock(&(info->printer_mutex));
	printf("locked\n");
	pthread_mutex_unlock(&(info->printer_mutex));
	pthread_mutex_lock(&(info->printer_mutex));
	printf("locked again\n");
	pthread_mutex_unlock(&(info->printer_mutex));
	pthread_mutex_lock(&(info->printer_mutex));
	printf("locked again and again\n");
	ft_debuger(args, info);
	ft_free_all(args, info);
	return (ret_value);
}
