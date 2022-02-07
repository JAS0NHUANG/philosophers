#include "philo.h"


int	ft_init_all(t_all **all)
{
	*all = malloc(sizeof(t_all));
	if (!(*all))
		ft_free_and_exit(NULL, ERR_MALLOC);
	(*all)->info = NULL;
	(*all)->philos_array = NULL;
	(*all)->forks_array = NULL;
	return (0);
}

int	main(int ac, char **av)
{
	t_all	*all;

	ft_init_all(&all);
	ft_get_info(ac, av, &all);
	ft_living_philosophers(all);
	ft_free_and_exit(all, ret_value);
	return (0);
}
