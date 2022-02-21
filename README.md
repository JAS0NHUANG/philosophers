# Philosophers

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
- Introduction to multi-threading programing.  
- The usage of time related functions: `gettimeofday()` and `usleep()`  
- How to use `pthread_*` functions.  
	(`pthread_create()`, `pthread_mutex_*` ... etc)  
- How to manipulate mutexes. 

## The MAKING:  
1. Set up a `t_data` struct to hold arguments and other useful info.  

```
t_all
┃
┃  /* arguments */
┣━ (int)nbr_philo;
┃
┣━ (int)t_t_die;
┃
┣━ (int)t_t_eat;
┃
┣━ (int)t_t_sleep;
┃
┣━ (int)must_eat;
┃
┃  /* others */
┣━ (int)fed;
┃
┣━ (int)death;
┃
┣━ (unsigned long)start_time;
┃
┣━ (pthread_mutex_t)common_lock;
┃
┣━ (t_philo *)philos_array
┃  [(t_philo 1), (t_philo 2), ..., (t_philo z)]
┃
┗━ (pthread_mutex_t *)forks_array
   [(fork 1), (fork 2), ..., (fork z)]
```

2. Set up a `t_philo` struct to hold each philo's info.  

```
t_philo
┃
┣━ (int)philo_index;
┃
┣━ (pthread_t)philo_thread;
┃
┣━ (unsigned long)last_meal_time;
┃
┣━ (int)meal_eaten;
┃
┣━ (int)has_right_fork;
┃
┗━ (int)has_left_fork;
```

3. create as many `t_philo`s according to the `number_of_philosophers`.  
	store them into an array and put the pointer in `t_data`.  
4. Create a `forks_array` to hold all "forks"(mutex) and also put a pointer in `t_data`.    
5. Write functions to check and store arguments.  
6. Write functions to initialize information needed during the simulation.  
7. Initialize all the `mutexs`(forks) and the `common_lock`.  
8. Write the `ft_philo_routine` function  as it will be called in each thread.  
	inside the routine function:  
	- Check if anybody is dead or if all philos are fed `must_eat` times.  
	- Write all the "action" functions (take forks, eat, putdown forks, sleep, think).  
	- Do some conditional check whenever needed.  
	- Use the `common_lock` whenever there is possiable data race situation.   

### Tests  
| test | resultat attendu |
|----------|-------|
| ./philo 1 200 200 200 | philo 1 ne prend qu'une fourchette et meurt au bout de 200 ms |
| ./philo 2 800 200 200 | personne ne meurt |
| ./philo 5 800 200 200 | personne ne meurt |
| ./philo 5 800 200 200 7 | la simulation s'arrete quand chaque philo a mange 7 fois|
| ./philo 4 410 200 200 | personne ne meurt |
| ./philo 4 310 200 200 | un philo meurt |
| ./philo 4 500 200 1.2 | argument invalide |
| ./philo 4 0 200 200 | argument invalide|
| ./philo 4 -500 200 200 | argument invalide |
| ./philo 4 500 200 2147483647 | un philo meurt au bout de 500 ms |
| ./philo 4 2147483647 200 200 | personne ne meurt |
| ./philo 4 214748364732 200 200 | argument invalide|
| ./philo 4 200 210 200 | un philo meurt, il faut afficher la mort avant 210 ms |

from https://github.com/iciamyplant/Philosophers

- Lazy Tester https://github.com/MichelleJiam/LazyPhilosophersTester
- Philosophers visualizer https://nafuka11.github.io/philosophers-visualizer/

### others:  
	Why the `*** stack smashing detected ***: terminated` error occured?  
	Why there will be SIGABRT?  
