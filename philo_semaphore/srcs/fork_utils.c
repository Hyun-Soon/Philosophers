#include "philosophers_semaphore.h"

void	up_hold_forks(t_bundle *bundle)
{
	sem_wait(bundle->t_personal_eat_cnt_sem);
	bundle->hold_forks++;
	sem_post(bundle->t_personal_eat_cnt_sem);
}

void	down_hold_forks(t_bundle *bundle)
{
	sem_wait(bundle->t_personal_eat_cnt_sem);
	bundle->hold_forks--;
	sem_post(bundle->t_personal_eat_cnt_sem);
}
