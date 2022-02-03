#include "philo.h"

void	ft_print_error(int error_code)
{
	if (error_code == 1)
		printf("Wrong amount of arguments.\n");
	else if (error_code == 2)
		printf("Only numeric arguments are allowed.\n");
	else if (error_code == 3)
		printf("Only positive numbers are allowed.\n");
	return ;
}
