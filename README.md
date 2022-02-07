# Philosophers
How about some thinking, eating, sleeping PHILOSOPHERs.

## Subject:  

N Philosophers  
N Forks  
Philosophers need 2 Forks to eat  
Keep Philosophers alive  

### Arguments:  

- `number_of_philosophers`  
- `time_to_die`  
	The time between the philo STARTED a meal and needs to start the next meal.  
	(start eating -> finish eating -> sleep -> (think) -> start eating).  
- `time_to_eat`
	The time needed for each philosopher to finish a meal.  
	(take up both forks -> put down both forks)  
- `time_to_sleep`  
	The time needed for each philosopher to sleep.  
	(satart to sleep -> wake up)  
- `[number_of_times_each_philosopher_must_eat]`  
	Optional. The number of time each philosopher must eat.  
	(Ex: 3 means each philosopher must eat "AT LEAST" 3 meals.)  

## What to learn:  

### Notions:  
- The usage of time related functions: `gettimeofday()` and `usleep()`  
- How to use `pthread_*` functions.  
	(`pthread_create()`, `pthread_mutex_*` ... etc)  
- How to manipulate mutexes. 
- calling `pthread_mutex_lock` multiple times in the same thread without unlock  
	(the code after the second one will be suspended.)  
- others:  
	Why the `*** stack smashing detected ***: terminated` error occured?  
	Why there will be SIGABRT?  

## Planning:  

### The MAKING:  
1. Set up a GLOBAL container `t_all` to hold other struct's pointer.  
2. Set up a `t_info` struct to hold arguments and other useful info.  
3. Set up a `t_philo` struct to hold each philo's info.  
	(create as many `t_philo`s according to the `number_of_philosophers`.)  
4. Create a `forks_array` to hold all "forks"(mutex).  

```
t_all
	┃
	┣━ (t_info *)info
	┃
	┣━ (t_philo *)philos_array
	┃  [(t_philo 1), (t_philo 2), ..., (t_philo z)]
	┃
	┗━ (pthread_mutex_t *)forks_array
	   [(fork 1), (fork 2), ..., (fork z)]

t_info
	┃  /* arguments */
	┣━ (int)nbr_philo;
	┃
	┣━ (int)t_t_die;
	┃
	┣━ (int)t_t_eat;
	┃
	┣━ (int)t_t_sleep;
	┃
	┣━ (int)times_must_eat;
	┃  /* others */
	┣━ (unsigned long)start_time;
	┃
	┗━ (pthread_mutex_t)printer_lock;

t_philo
	┃
	┣━ (int)philo_index;
	┃
	┣━ (pthread_t)philo_thread;
	┃
	┣━ (int)meal_eaten;
	┃
	┗━ (int)last_meal_time;
```

3. Write functions to check and store arguments.  
4. Write functions to initialize information needed during the simulation.  
5. Create "philo" threads and all the "forks(mutexs)".  
6. Write the logic about the simulation.  

### How the program will run:  
steps:
1. get arguments(`ft_get_args`) -> check arguments
2. `init_data` (init needed data. Ex: start time, `printer_lock`, 
3. `init_philo`. 
4. start running simulation.  
