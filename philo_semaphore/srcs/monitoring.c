#include "philosophers_semaphore.h"

void	exit_full(t_bundle *bundle)
{
	sem_post(bundle->t_eat_cnt_sem);
	return_forks(bundle);
	close_sems(bundle);
	exit(0);
}

void	exit_starve(t_bundle *bundle, struct timeval s_now)
{
	sem_wait(bundle->t_print_semaphore);
	printf("%ld	%d died\n",
		get_timestamp(bundle, s_now), bundle->id + 1);
	close_sems(bundle);
	exit(1);
}

void	*monitoring(void *bd)
{
	t_bundle		*bundle;
	struct timeval	s_now;

	bundle = (t_bundle *)bd;
	while (1)
	{
		gettimeofday(&s_now, NULL);
		sem_wait(bundle->t_eat_time_sem);
		if (get_time_since(bundle->s_eat_time, s_now)
			>= bundle->time_to_die)
			exit_starve(bundle, s_now);
		sem_post(bundle->t_eat_time_sem);
		sem_wait(bundle->t_personal_eat_cnt_sem);
		if (bundle->eat_cnt == bundle->number_of_times_for_each)
			exit_full(bundle);
		sem_post(bundle->t_personal_eat_cnt_sem);
		usleep(DT);
	}
	exit(2);
}

void	close_sems(t_bundle *bundle)
{
	if (sem_close(bundle->t_eat_time_sem) == -1)
		exit(51);
	if (sem_close(bundle->t_personal_eat_cnt_sem) == -1)
		exit(52);
}
