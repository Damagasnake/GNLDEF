/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidma2 <davidma2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:13:20 by davidma2          #+#    #+#             */
/*   Updated: 2024/11/14 13:59:06 by davidma2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#include <unistd.h>
#include <stdlib.h>

char	*bytesr_filling(int fd, char *bytesr, char *buffer);
char	*extract_new_bytesr(char	*bytesr);
char	*extract_line(char *bytesr, char *line);
char *ft_strjoin(char *s1, const char *s2);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
