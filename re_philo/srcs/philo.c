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
	int		ret_value;
	t_all	*all;

	ft_init_all(&all);
	ret_value = ft_get_info(ac, av, &all);
	if (ret_value)
		ft_free_and_exit(all, ret_value);
	ret_value = ft_living_philosophers(&all);
	if (ret_value)
		ft_free_and_exit(all, ret_value);
	ft_free_and_exit(all, ret_value);
	return (0);
}
