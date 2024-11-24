/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:17:37 by aboukhmi          #+#    #+#             */
/*   Updated: 2024/11/24 23:24:52 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}

char	*get_backup_bonus(int fd, char *backup)
{
	char	*mini_buff;
	ssize_t	l;

	l = 1;
	mini_buff = (char *)ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	while (l > 0 && !ft_strchr(backup, '\n'))
	{
		l = read(fd, mini_buff, BUFFER_SIZE);
		if (l == -1)
		{
			free(mini_buff);
			free(backup);
			return (NULL);
		}
		mini_buff[l] = '\0';
		backup = ft_strjoin(backup, mini_buff);
	}
	free(mini_buff);
	return (backup);
}

char	*get_line_bonus(char *backup)
{
	int		i;
	int		j;
	char	*res_line;

	i = 0;
	j = 0;
	if (!backup || !*backup)
		return (NULL);
	while (backup[i] != '\n' && backup[i])
		i++;
	if (backup[i] == '\n')
		i++;
	res_line = (char *)ft_calloc(i + 1, sizeof(char));
	while (j < i)
	{
		res_line[j] = backup[j];
		j++;
	}
	res_line[j] = '\0';
	return (res_line);
}

char	*update_backup_bonus(char *backup)
{
	char	*new_backup;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (backup[i] != '\n' && backup[i])
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	new_backup = (char *)ft_calloc(((ft_strlen(backup) - i) + 1), sizeof(char));
	i++;
	while (backup[i] != '\0')
		new_backup[j++] = backup[i++];
	new_backup[j] = '\0';
	free(backup);
	return (new_backup);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	backup[fd] = get_backup_bonus(fd, backup[fd]);
	if (!backup[fd])
		return (NULL);
	line = get_line_bonus(backup[fd]);
	backup[fd] = update_backup_bonus(backup[fd]);
	return (line);
}