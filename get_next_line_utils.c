/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlahmaid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:55:13 by rlahmaid          #+#    #+#             */
/*   Updated: 2019/12/04 10:41:10 by rlahmaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (*(s1 + i))
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (((char *)s) + i);
		i++;
	}
	if (s[i] == c)
		return (((char *)s) + i);
	else
		return (NULL);
}

char		*ft_strjoin(char  *s1, char  *s2)
{
	size_t		i;
	char		*s;

	i = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!(s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (*s1)
	{
		*(s + i) = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		*(s + i) = *s2;
		i++;
		s2++;
	}
	*(s + i) = '\0';
	return (s);
}

char		*ft_strndup(const char *s1, size_t n)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s1);
	if (n > i)
		ptr = (char *)malloc((i + 1) * sizeof(char));
	else
		ptr = (char *)malloc((n + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (*(s1 + i) && n--)
	{
		*(ptr + i) = *(s1 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
