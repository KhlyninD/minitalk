/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:28:42 by mjhin             #+#    #+#             */
/*   Updated: 2022/01/24 14:56:28 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum, siginfo_t *siginfo, void *context)
{
	static int		bit = 0;
	static char		mess = 0;
	static pid_t	cl_pid;

	(void)context;
	if (cl_pid != siginfo->si_pid)
	{
		cl_pid = siginfo->si_pid;
		bit = 0;
		mess = 0;
	}
	if (signum == SIGUSR1)
		mess |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putstr(&mess);
		mess = 0;
		bit = 0;
	}
	usleep(100);
	if (kill(siginfo->si_pid, SIGUSR1))
		exit(2);
}

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	ft_putstr("server pid: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &action, NULL))
		exit(1);
	if (sigaction(SIGUSR2, &action, NULL))
		exit(1);
	while (1)
		pause();
	return (0);
}
