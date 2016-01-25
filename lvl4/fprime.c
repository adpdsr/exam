/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:53:11 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/01/25 16:25:40 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // atoi
#include <stdio.h> // printf

int	fprime(int nb)
{
	int n;
	
	if (nb == 0)
	{
		printf("0");
		return (0);
	}
	if (nb == 1)
	{
		printf("1");
		return (0);
	}
	while (1)
	{
		n = 1;
		while (++n <= nb)
		{
			if (nb % n == 0)
			{
				printf("%d", n);
				nb = nb / n;
				break;
			}
		}
		if (nb == 1)
			break;
		else
			printf("*");
	}
	return (0);
}

int		main(int ac, char **av)
{
	int ret;

	if (ac == 2)
	{
		if (!(av[1][0]))
		{
			printf("\n");
			return (0);
		}
		ret = fprime(atoi(av[1]));
	}
	printf("\n");
	return (0);
}
