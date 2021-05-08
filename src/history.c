/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 01:32:20 by mhufflep          #+#    #+#             */
/*   Updated: 2021/05/08 06:08:59 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_history_filename(void)
{
	char *path;

	path = ft_strjoin(HISTORY_FILEPATH, HISTORY_FILENAME); //memory leak, fuck
	return (path);
}

int		read_history(t_prm *prm)
{
	t_bd_lst *new;
	char *path;
	char *line;
	int fd;
	int res;

	line = NULL;
	path = get_history_filename();
	fd = open(path, O_CREAT | O_RDONLY, 777);
	if (fd < 0)
		return (-2);
	res = get_next_line(fd, &line);
	while (res == 1)
	{
		new = bd_lstnew(line);
		if (new == NULL)
		{
			res = -3;
			break ;
		}
		bd_lstadd_back(&(prm->history), new);
		res = get_next_line(fd, &line);
	}
	//need to free line
	if (res < 0)
	{
		bd_lstclear(&(prm->history), free);
	}
	prm->history_ptr = bd_lstlast(prm->history);
	close(fd);
	return (res);
}

int		history_add(t_bd_lst *node)
{
	char *path;
	int fd;

	path = get_history_filename();
	if (!path)
		return (-1);
	fd = open(path, O_APPEND | O_WRONLY);
	if (fd < 0)
		return (-2);
	
	if (node && node->content)
	{
		write(fd, node->content, bd_strlen((char *)node->content));
		if (node->next)
			write(fd, "\n", 1);
	}
	close(fd);
	return (0);
}
