/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:23:33 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/02/01 12:13:09 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // printf
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstri(char *s, int end)
{
	int i;

	i = 0;
	while (i < end)
	{
		ft_putchar(s[i]);
		i++;
	}
}

char 	*rev_wstr(char *s)
{
	int i;
	int j;
	int end;
	char *cpy;

	j = 0;
	end = ft_strlen(s) - 1;
	if (!(cpy = (char *)malloc(sizeof(char) * end + 2)))
		return (NULL);
	while (end > 0)
	{
		while (end > 0 && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		{
			end--;
		}
		if (end - 1 > 0 && s[end] != ' ' && s[end] != '\t' && s[end] != '\n')
		{
			while (end + 1 > 0 && s[end] != ' ' && s[end] != '\t' && s[end] != '\n')
				end--;
			i = end + 1;
			while (s[i] && s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			{
				cpy[j] = s[i];
				j++;
				i++;
			}
			end--;
			cpy[j++] = ' ';
		}
	}
	return (cpy);
}

int		main(void)
{
	char s[] = "         mot1     mot2      mot3       mot4         mot5           z      ";
	char *cpy;

	cpy = rev_wstr(s);
	ft_putstri(cpy, ft_strlen(cpy) - 4);
	return (0);
}
