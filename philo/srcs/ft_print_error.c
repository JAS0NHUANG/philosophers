#include "philo.h"

void	ft_print_error(int error_code)
{
	if (error_code == ERR_ARGS_AMOUNT)
		printf("Error: Wrong amount of arguments.\n");
	if (error_code == ERR_ARGS_NAN)
		printf("Error: Only numeric arguments are allowed.\n");
	if (error_code == ERR_ARGS_NEG)
		printf("Error: Only positive numbers are allowed.\n");
	if (error_code == ERR_INIT)
		printf("Error: Initialization failed.\n");
	return ;
}
