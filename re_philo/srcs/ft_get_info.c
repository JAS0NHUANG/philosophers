#include "philo.h"

int	ft_init_info(t_info	**info)
{
	*info = malloc(sizeof(t_info));
	if (!(*info))
		return (ERR_MALLOC);
	printf("info pointer: %p\n", (*info));
	(*info)->nbr_philo = 0;
	(*info)->t_t_die = 0;
	(*info)->t_t_eat = 0;
	(*info)->t_t_sleep = 0;
	(*info)->must_eat = 0;
	(*info)->start_time = 0;
	if (pthread_mutex_init(&((*info)->printer_lock), 0) != 0 || \
		pthread_mutex_init(&((*info)->life_check_lock), 0) != 0)
		return (ERR_MUTEX);
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
		index++;
	}
	return (0);
}

int	ft_get_info(int ac, char **av, t_all **all)
{
	int		ret_value;
	t_info	*info;

	ret_value = 0;
	ret_value = ft_check_args(ac, av);
	if (ret_value == 0)
	{
		ft_init_info(&info);
		info->nbr_philo = ft_atoi(av[1]);
		info->t_t_die = ft_atoi(av[2]);
		info->t_t_eat = ft_atoi(av[3]);
		info->t_t_sleep = ft_atoi(av[4]);
		if (av[5])
			info->must_eat = ft_atoi(av[5]);
		(*all)->info = info;
		printf("info pointer: %p\n", (info));
	}
	return (ret_value);
}
