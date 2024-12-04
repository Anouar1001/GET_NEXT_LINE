/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 23:20:18 by aboukhmi          #+#    #+#             */
/*   Updated: 2024/11/25 19:43:51 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);

char	*ft_strdup(const char *s);

char	*ft_strjoin(char *s1, const char *s2);

size_t	ft_strlen(const char *str);

#endif
