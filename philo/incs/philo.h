/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jahuang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:46:24 by jahuang           #+#    #+#             */
/*   Updated: 2022/02/18 09:58:21 by jahuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*---------------------------------------------------------------------------->>
**    enum
*/

enum	e_error_code
{
	ERR_ARGS_AMOUNT = 1,
	ERR_ARGS_NAN,
	ERR_ARGS_NEG,
	ERR_ARGS_EMPTY,
	ERR_ARGS_NOPHILO,
	ERR_ARGS_TOOLONG,
	ERR_GETTIME,
	ERR_INIT,
	ERR_MALLOC,
	ERR_MUTEX,
	ERR_PTHREAD,
};

enum	e_actions
{
	TAKE_FORK = 1,
	EAT,
	SLEEP,
	THINK,
	DIE,
};

/*---------------------------------------------------------------------------->>
**    structs
*/

typedef struct s_data
{
	int				nbr_philo;
	int				t_t_die;
	int				t_t_eat;
	int				t_t_sleep;
	int				must_eat;
	int				fed;
	int				death;
	unsigned long	start_time;
	pthread_mutex_t	common_lock;
	pthread_mutex_t	*forks_array;
	struct s_philo	*philos_array;
}		t_data;

typedef struct s_philo
{
	int				philo_index;
	pthread_t		philo_thread;
	unsigned long	last_meal_time;
	int				meal_eaten;
	int				has_left_fork;
	int				has_right_fork;
	t_data			*data;
}		t_philo;

/*---------------------------------------------------------------------------->>
**	srcs
*/
int				ft_get_data(int ac, char **av, t_data **data);
int				ft_init_mutexs(t_data **data);
int				ft_run_philo(t_data **data);
int				ft_still_alive(t_philo **philo);
int				ft_all_fed(t_philo **philo);
int				ft_take_forks(t_philo **philo);
int				ft_eating(t_philo **philo);
int				ft_sleeping(t_philo **philo);
int				ft_thinking(t_philo **philo);
int				ft_putdown_forks(t_philo **philo);
void			ft_print_action(t_philo **philo, int action);

/*---------------------------------------------------------------------------->>
**	utils
*/
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
unsigned long	ft_get_time_in_ms(void);
void			ft_sleep_ms(unsigned long ms);

#endif
