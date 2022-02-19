#include "philo.h"

static void	ft_init_args(t_args **args)
{
	*args = malloc(sizeof(t_args) * 1);
	(*args)->nbr_philo = 0;
	(*args)->t_t_die = 0;
	(*args)->t_t_eat = 0;
	(*args)->t_t_sleep = 0;
	(*args)->must_eat = -1;
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

int	ft_get_args(int ac, char **av, t_args **args)
{
	int	ret_value;

	ret_value = 0;
	ret_value = ft_check_args(ac, av);
	if (ret_value == 0)
	{
		ft_init_args(args);
		(*args)->nbr_philo = ft_atoi(av[1]);
		(*args)->t_t_die = ft_atoi(av[2]);
		(*args)->t_t_eat = ft_atoi(av[3]);
		(*args)->t_t_sleep = ft_atoi(av[4]);
		if (av[5])
			(*args)->must_eat = ft_atoi(av[5]);
	}
	return (ret_value);
}
