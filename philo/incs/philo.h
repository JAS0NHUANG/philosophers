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

typedef struct	s_all
{
	t_info			*info;
	t_philo			*philos_array;
	pthread_mutex_t	*forks_array;
}	t_all;

typedef struct	s_info
{
	int				nbr_philo;
	int				t_t_die;
	int				t_t_eat;
	int				t_t_sleep;
	int				must_eat;
	unsigned long	start_time;
	pthread_mutex_t	printer_lock;
	pthread_mutex_t	checker_lock;
}		t_info;

typedef struct	s_philo
{
	int				philo_index;
	pthread_t		philo_thread;
	int				meal_eaten;
	int				last_meal_time;
}		t_philo;

/*--------------------------------------------------------------------------->>
**	philo.c
*/
int		ft_get_args(int ac, char **av, t_info **info);
int		ft_init_data(t_info **info);
void	ft_print_error(int error_code);
void	ft_free_all(t_all *all);

/*--------------------------------------------------------------------------->>
*	utils
*/
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
unsigned long	ft_get_time_in_ms(void);
void			ft_debuger(t_all *all);

#endif
