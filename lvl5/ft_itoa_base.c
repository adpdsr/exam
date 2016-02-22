/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adu-pelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 16:19:45 by adu-pelo          #+#    #+#             */
/*   Updated: 2016/02/22 16:24:01 by adu-pelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char		*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char		*ft_strdup(char *s1)
{
	char *s2;

	if (!(s2 = (char *)malloc(sizeof(char) * ft_strlen(s1))))
		return (NULL);
	return (ft_strcpy(s2, s1));
}

static char		*ft_convert(int nb, char *s, int base, int i)
{
	int			j;
	const char	letter[16] = "0123456789ABCDEF";

	j = 0;
	if (nb < 0)
	{
		if (base == 10)
		{
			s[j] = '-';
			j++;
		}
		nb = -nb;
	}
	i = 1;
	while (nb / i > base - 1)
		i = i * base;
	while (i != 0)
	{
		s[j] = letter[nb / i];
		nb = nb % i;
		i = i / base;
		j++;
	}
	s[j] = '\0';
	return (s);
}

char			*ft_itoa_base(int value, int base)
{
	int 	count;
	int		i;
	char	*s;

	if (value == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		count = 0;
		i = value;
		while (i > 0)
		{
			count++;
			i = i / base;
		}
		s = (char *)malloc(sizeof(char) * count + 1);
		s = ft_convert(value, s, base, 0);
		return (s);
	}
}
