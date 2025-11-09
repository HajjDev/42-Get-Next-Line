/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 23:00:07 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/09 23:04:08 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ********* */
/* Libraries */
/* ********* */

# include <unistd.h>
# include <stdlib.h>

/* ************************** */
/* Buffer Set-Up and Handling */
/* ************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* ********* */
/* Functions */
/* ********* */

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_find(char const *s, char c);
char	*extract_line(char *buffer);
char	*clear_buffer(char *buffer);
char	*ft_strdup(const char *s1);
char	*ft_error(char *buffer);
size_t	ft_strlen(char const *s);

#endif