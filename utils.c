/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjhin <mjhin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:49:49 by mjhin             #+#    #+#             */
/*   Updated: 2022/01/24 14:11:55 by mjhin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putnbr(int n)
{
	long long int	t;

	t = n;
	if (t < 0)
	{
		t *= -1;
		ft_putchar('-');
	}
	if (t > 9)
	{
		ft_putnbr((t / 10));
		ft_putchar((t % 10 + '0'));
	}
	else
		ft_putchar((t + '0'));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	return (res * sign);
}
