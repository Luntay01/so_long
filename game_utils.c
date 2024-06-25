/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:17:05 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/22 16:45:38 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

int	count_number(long n)
{
	int	count;

	count = 1;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*mod_ft_itoa(int n)
{
	long	num;
	char	*str;
	int		len;

	num = n;
	len = count_number(num);
	if (num < 0)
	{
		num = -num;
		len++;
	}
	str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	str[len] = 0;
	while (len-- > 0)
	{
		str[len] = (num % 10) + 48;
		num = num / 10;
	}
	if (n < 0)
		str[0] = 45;
	return (str);
}

float	c_angle(float startX, float startY, float targetX, float targetY)
{
	float	dx;
	float	dy;
	float	angle;

	dx = targetX - startX;
	dy = targetY - startY;
	angle = atan2(dy, dx) * 180.0f / M_PI;
	if (angle < 0.0f)
		angle += 360.0f;
	return (angle);
}
