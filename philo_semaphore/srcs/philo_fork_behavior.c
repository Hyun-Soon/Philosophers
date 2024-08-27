#include "philosophers_semaphore.h"

void	print_get_fork(t_bundle *bundle)
{
	struct timeval	s_now;
	long			time_since_last_meal;
	long			temp_timestamp;

	gettimeofday(&s_now, NULL);
	sem_wait(bundle->t_eat_time_sem);
	time_since_last_meal = get_time_since(bundle->s_eat_time, s_now);
	sem_post(bundle->t_eat_time_sem);
	sem_wait(bundle->t_personal_eat_cnt_sem);
	if (time_since_last_meal < bundle->time_to_die
		&& bundle->eat_cnt != bundle->number_of_times_for_each)
	{
		sem_post(bundle->t_personal_eat_cnt_sem);
		sem_wait(bundle->t_print_semaphore);
		temp_timestamp = get_timestamp(bundle, s_now);
		printf("%ld	%d has taken a fork\n", temp_timestamp, bundle->id + 1);
		sem_post(bundle->t_print_semaphore);
	}
	else
		sem_post(bundle->t_personal_eat_cnt_sem);
}

void	get_forks(t_bundle *bundle)
{
	sem_wait(bundle->t_semaphore);
	up_hold_forks(bundle);
	print_get_fork(bundle);
	sem_wait(bundle->t_semaphore);
	up_hold_forks(bundle);
	print_get_fork(bundle);
}
