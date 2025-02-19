# philosophers

This program simulates the dining philosophers problem in C. It has two versions, the classic dining philosohpers problem (V1) and a version where the "forks" are in the middle of the table.

Version 1 uses threads and mutexes. Version 2 uses semaphores and subprocesses.

## General Requirements  

- Must follow the [Norminette](https://github.com/42School/norminette) style guide.
- Allowed functions (V1): memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
- Allowed functions (V2): memset, printf, malloc, free, write, fork, kill, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink
- Projects should not have memory leaks or terminate unexpectedly.
- Must submit a Makefile with specified rules that compiles the program.

## Requirements

Usage

```
	./philo number_of_philosohpers time_to_die time_to_eat time_to_sleep [number_of_meals]
```

Time to die is the time a philosopher has to eat before it starves. 

Time to eat is the time a philosopher takes to eat a meal.

Time to sleep is the time the philosopher sleeps.

Number of meals, if present, is the amount of eaten meals it takes for the simulation to end, if every philosopher ate at least that quantity.

Some constraints are applied to testing the program. No more than 200 philosophers should be used, and timers should be higher than 60ms.

Deadlocks must be avoided.

### Version 1

Philosophers (threads) sit on a round table, between each philosopher there's a fork (mutex). A philosopher must take the two forks at his side to eat, competing against other philosophers.

### Version 2

Forks (A semaphore) are in the middle of the table. Philosophers still should take two forks to eat, competing for a pool of resources.
