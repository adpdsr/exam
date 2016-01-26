/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:43:35 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/01/26 13:06:42 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int tmp;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
				i = 0;
			}
			else
				i++;
		}
	}
}

int		main(void)
{
	int i = 0;
	int tab[7] = {0, 2, 2, 9, 4, 1, 3};

	sort_int_tab(tab, 7);
	while (i < 7)
	{
		printf("case %d is : %d\n", i, tab[i]);
		i++;
	}
	return (0);
}
