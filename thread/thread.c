#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct s_info
{
	int		number;
	pthread_t	thread_id;
}	t_info;

void	*ft_routine(void *info_object)
{
	t_info	*info_holder;

	info_holder = (t_info *)info_object;
	printf("the index: %d\n", info_holder->number);
	printf("hello\n");
}

int	main()
{
	t_info	**info;
	int	index;

	info = malloc(sizeof(t_info *) * 10);
	index = 0;
	while (index < 10)
	{
		info[index] = malloc(sizeof(t_info));
		info[index]->number = index;
		pthread_create(&(info[index]->thread_id), NULL, &ft_routine, (void *)info[index]);
		index++;
	}
	index = 0;
	while (index < 10)
	{
		pthread_join(info[index]->thread_id, NULL);
		index++;
	}
	if (info)
	{
		index = 0;
		while (index < 10)
		{
			free(info[index]);
			index++;
		}
		free(info);
	}

}
