/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-hajj <cel-hajj@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 23:00:07 by cel-hajj          #+#    #+#             */
/*   Updated: 2025/11/11 13:11:56 by cel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 42
#  elif BUFFER_SIZE > 8000000
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 1000000
#  endif
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