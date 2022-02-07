# philosophers
How about some thinking, eating, sleeping people.

# philosophers
How about some thinking, eating, sleeping people.


## Subject:  

### Arguments:  

- `number_of_philosophers`  
- `time_to_die`  
	The time between the philosopher STARTED a meal and needs to start the next meal. (start eating -> finish eating -> sleep -> (think) -> start eating).  
- `time_to_eat`
	The time needed for each philosopher to finish a meal. (take up both forks -> put down both forks)  
- `time_to_sleep`  
	The time needed for each philosopher to sleep. (satart to sleep -> wake up)  
- `[number_of_times_each_philosopher_must_eat]`  
	Optional. The number of time each philosopher must eat. (Ex: 3 means each philosopher must eat "AT LEAST" 3 meals.)  

### Notions:  
- The return vale of `gettimeofday()`
- How to use `pthread_*` functions.(`pthread_create()`, `pthread_mutex_*` ... etc)  
- How to manipulate mutexes. 
- after `pthread_mutex_init`, we don't really need to destroy?  
- calling `pthread_mutex_lock` multiple times in the same thread without unlock (the code after the second one will be suspended.)    

### The MAKING:  
1. Set up a `t_data` struct to store necessary informations.
2. Set up a `t_philo` struct and create as many `t_philo`s according to the argument(`number_of_philosophers`) given.  
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
