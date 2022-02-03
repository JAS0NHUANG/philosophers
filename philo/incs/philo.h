#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

/*--------------------------------------------------------------------------->>
**    enum
*/

enum	e_error_code
{
	ERR_ARGS_AMOUNT = 1,
	ERR_ARGS_NAN,
	ERR_ARGS_NEG,
	ERR_GETTIME,
};

/*--------------------------------------------------------------------------->>
**    structs
*/

typedef struct	s_args
{
	int	nbr_philo;
	int	t_t_die;
	int	t_t_eat;
	int	t_t_sleep;
	int	must_eat;
}		t_args;

typedef struct	s_philo
{
	pthread_t		philo_thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	int				meal_eaten;
}		t_philo;

typedef struct	s_data
{
	t_philo			*philos_array;
	unsigned long	start_time;
	pthread_mutex_t	printer_lock;
	pthread_mutex_t	meal_eaten_lock;
}		t_data;

/*--------------------------------------------------------------------------->>
**	philo.c
*/
int		ft_get_args(int ac, char **av, t_args **args);
int		ft_init_data(t_data **data);
void	ft_print_error(int error_code);
void	ft_free_all(t_args *args, t_data *data);

/*--------------------------------------------------------------------------->>
*	utils
*/
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
unsigned long	ft_get_time_in_ms(void);
void			ft_debuger(t_args *args, t_data *data);

#endif
