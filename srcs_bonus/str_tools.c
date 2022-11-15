/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarion <emarion@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:48:33 by emarion           #+#    #+#             */
/*   Updated: 2022/02/25 00:48:33 by emarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0 || !s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(1, &"\n", 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len ++;
	}
	return (len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (s1 && s2)
	{
		if ((((unsigned char)*s1 - (unsigned char)*s2) != 0)
			|| *s1 == '\0' || *s2 == '\0')
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1 ++;
		s2 ++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (!(s1 && s2))
		return (NULL);
	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	mem = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!mem)
		return (NULL);
	while (++ i < len1)
		mem[i] = s1[i];
	i = -1;
	while (++ i < len2)
		mem[len1 + i] = s2[i];
	mem[len1 + i] = '\0';
	return (mem);
}
