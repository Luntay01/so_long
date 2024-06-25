/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmordaun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:07:12 by kmordaun          #+#    #+#             */
/*   Updated: 2023/08/24 18:16:17 by kmordaun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*copy_leftovers(char *s_str)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (s_str[i] != '\n' && s_str[i])
		i++;
	if (!s_str[i])
	{
		free(s_str);
		return (0);
	}
	j = mod_strlen(s_str) - i;
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (str == 0)
		return (0);
	j = 0;
	i++;
	while (s_str[i])
		str[j++] = s_str[i++];
	free(s_str);
	str[j] = 0;
	return (str);
}

char	*copy_line(char *s_str)
{
	int		i;
	char	*str;

	i = 0;
	if (s_str[i] == 0)
		return (0);
	while (s_str[i] != '\n' && s_str[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (str == 0)
		return (0);
	i = 0;
	while (s_str[i] != '\n' && s_str[i])
	{
		str[i] = s_str[i];
		i++;
	}
	if (s_str[i] == '\n')
	{
		str[i] = s_str[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*read_file_allocate(int fd, char *s_str)
{
	char		*buff;
	int			read_fd;

	read_fd = 1;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == 0)
		return (0);
	while (!mod_strchr(s_str, '\n') && read_fd != 0)
	{
		read_fd = read(fd, buff, BUFFER_SIZE);
		if (read_fd == -1)
		{
			free(s_str);
			free(buff);
			s_str = NULL;
			return (0);
		}
		buff[read_fd] = '\0';
		s_str = mod_strjoin(s_str, buff);
	}
	free(buff);
	return (s_str);
}

char	*get_next_line(int fd)
{
	static char	*s_str = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	s_str = read_file_allocate(fd, s_str);
	if (s_str == 0)
		return (0);
	line = copy_line(s_str);
	s_str = copy_leftovers(s_str);
	return (line);
}
/*
#include	<stdio.h>
#include	<fcntl.h>
int main() 
{
    int fd = open("testfile.txt", O_RDONLY);
    if (!fd) {
        fprintf(stderr, "Failed to open the file.\n");
        return 1;
    }

    char* line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
*/
