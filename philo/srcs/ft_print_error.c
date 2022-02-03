#include "philo.h"

void	ft_print_error(int error_code)
{
	if (error_code == ERR_ARGS_AMOUNT)
		printf("Wrong amount of arguments.\n");
	else if (error_code == ERR_ARGS_NAN)
		printf("Only numeric arguments are allowed.\n");
	else if (error_code == ERR_ARGS_NEG)
		printf("Only positive numbers are allowed.\n");
	return ;
}
