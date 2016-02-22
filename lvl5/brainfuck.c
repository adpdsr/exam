/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:15:17 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/02/22 16:36:26 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_count(char *s, int i)
{
	int count;

	count = 0;
	while (1)
	{
		if (*s == '[')
			count++;
		else if (*s == ']')
			count--;
		if (count == 0)
			return (s);
		s += i;
	}
	return (NULL);
}

void	brainfuck(char *s, char *buf)
{
	while (*s)
	{
		if (*s == '>')
			buf++;
		else if (*s == '<')
			buf--;
		else if (*s == '+')
			(*buf)++;
		else if (*s == '-')
			(*buf)--;
		else if (*s == '.')
			write(1, buf, 1);
		else if (*s == '[' && !(*buf))
			s = ft_count(s, 1);
		else if (*s == ']' && *buf)
			s = ft_count(s, -1);
		s++;
	}
}

int		main(int ac, char **av)
{
	char	buf[2048];
	int 	i;

	if (ac > 1)
	{
		i = 0;
		while (i < 2048)
			buf[i++] = 0;
		brainfuck(av[1], buf);
	}
	else
		write(1, "\n", 1);
	return (0);
}
