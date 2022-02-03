# philosophers
How about some thinking, eating, sleeping people.

# philosophers
How about some thinking, eating, sleeping people.


### Subject:  

	Arguments: 
		number\_of\_philosophers
		time\_to\_die
		time\_to\_eat
		time\_to\_sleep
		[number\_of\_times\_each\_philosopher\_must\_eat]


### Notions:  
	- The return vale of "gettimeofday"
	- How to use "pthread\_\*" functions.(pthread\_create(), pthread\_mutex\_\* ... etc)  
	- How to manipulate mutexes. 
		- after "pthread\_mutex\_init", we don't really need to destroy?  
		- calling "pthread\_mutex\_lock" multiple times in the same thread will not block the code execution.  


### The MAKING:  
	1. Set up a "t\_shared\_info" struct to store necessary informations.
	2. Set up a "t\_philo" struct and create as many "t\_philo"s according to the argument(number\_of\_philosophers) given.  
	3. Write functions to check and store arguments.  
	4. Write functions to initialize information needed during the simulation.  
	5. Create "philo" threads and all the "forks(mutexs)".  
	6. Write the logic about the simulation.  

### How the program will run:  
	/* steps:
	 * 1. get_arguments -> check_arguments
	 * 2. ft_get_args -> init_info -> init_philo
	 * 3. start running simulation.
	 * 
	 */




