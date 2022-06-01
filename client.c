/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:57:10 by mjhin             #+#    #+#             */
/*   Updated: 2022/01/24 14:53:44 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	mess(int pid, char *mess)
{
	int	bit;
	int	i;

	i = 0;
	while (mess[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if (mess[i] & (1 << bit))
			{
				if (kill(pid, SIGUSR1))
					exit(2);
			}
			else
			{
				if (kill(pid, SIGUSR2))
					exit(2);
			}
			bit++;
			pause();
			usleep(100);
		}
		i++;
	}
}

static void	handler(int signum)
{
	static unsigned int	i = 0;

	(void)signum;
	if (!(i % 8))
		ft_putstr("OK!!!\n");
	i++;
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	action;

	if (argc != 3)
	{
		ft_putstr("NOT 3 ARGUMENTS!!!\n");
		return (1);
	}
	if (!ft_strlen(argv[2]))
	{
		ft_putstr("NOT MESSAGE!!!\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr("NOT VALID PID!!!\n");
		return (1);
	}
	action.sa_handler = handler;
	if (sigaction(SIGUSR1, &action, NULL))
		exit(1);
	mess(pid, argv[2]);
}
