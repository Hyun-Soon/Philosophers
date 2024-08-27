#include "../headers/philosophers.h"

void	print_die_msg(t_bundle *bundle, int dead)
{
	printf("%ld	%d died\n", get_time_since(bundle->s_start), dead);
}

int	atoi_args(t_bundle *bundle, t_philo *philos, int argc, char **argv)
{
	bundle->num_of_philos = my_atoi(argv[1]);
	bundle->time_to_die = my_atoi(argv[2]);
	bundle->time_to_eat = my_atoi(argv[3]);
	bundle->time_to_sleep = my_atoi(argv[4]);
	if (argc == 6)
		bundle->number_of_times_for_each = my_atoi(argv[5]);
	if (bundle->num_of_philos == -1
		|| bundle->number_of_times_for_each == -1
		|| bundle->time_to_die == -1
		|| bundle->time_to_eat == -1
		|| bundle->time_to_sleep == -1
		|| bundle->number_of_times_for_each == -1)
	{
		write(2, "arg err.\n", 9);
		return (-1);
	}
	return (setting_table(bundle, philos));
}

int	my_atoi(const char *str)
{
	long	ret;

	ret = 0;
	if (*str == 0)
		return (-1);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			return (-1);
		str++;
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		ret = ret * 10 + (long)(*str - '0');
		if (ret < -2147483648 || ret > 2147483647)
			return (-1);
		str++;
	}
	if (!ret)
		return (-1);
	return (ret);
}
